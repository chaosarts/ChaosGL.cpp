/*
 * Renderpass.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "Renderpass.hpp"
#include "Program.hpp"
#include "Drawable.hpp"
#include "cap.hpp"
#include "clearmask.hpp"

namespace chaosgl
{
	void Renderpass::render ()
	{
		{
			std::map<GLbitfield, clearmask*>::iterator it = _clearmasks.begin();
			GLbitfield mask = 0;
			
			while (it != _clearmasks.end())
			{
				it->second->clear();
				mask = mask | it->second->field;
				it++;
			}
			
			glClear(mask);
		}
		
		{
			std::map<GLenum, cap*>::iterator it = _caps.begin();
			while (it != _caps.end())
			{
				it->second->apply();
				it++;
			}
		}
		
		_beforeRender();
		_render();
		_afterRender();
		
		{
			std::map<GLenum, cap*>::iterator it = _caps.begin();
			while (it != _caps.end())
			{
				it->second->revert();
				it++;
			}
		}
	}
	
	
	void Renderpass::addDrawable (chaosgl::Drawable *drawable)
	{
		_drawables.push_back(drawable);
	}
	
	
	std::vector<Drawable*> Renderpass::getDrawables ()
	{
		return _drawables;
	}
	
	
	bool Renderpass::hasDrawable (chaosgl::Drawable *drawable)
	{
		return indexOf(drawable) >= 0;
	}
	
	
	int Renderpass::indexOf(chaosgl::Drawable *drawable)
	{
		std::vector<Drawable*>::iterator it = _drawables.begin();
		int index = 0;
		while (it != _drawables.end())
		{
			if (*it == drawable) return index;
			it++;
			index++;
		}
		
		return -1;
	}
	
	
	int Renderpass::removeDrawable (chaosgl::Drawable *drawable)
	{
		int index = indexOf(drawable);
		
		if (index >= 0) _drawables.erase(_drawables.begin() + index);
		
		return index;
	}
	
	
	Drawable* Renderpass::removeDrawable (int index)
	{
		if (index < 0 || index >= _drawables.size())
			return nullptr;
		
		std::vector<Drawable*>::iterator it = _drawables.begin() + index;
		_drawables.erase(it);
		return (*it);
	}
	
	
	void Renderpass::addCapability (cap* cap)
	{
		if (hasCapability(cap->name)) return;
		_caps[cap->name] = cap;
	}
	
	
	bool Renderpass::hasCapability (GLenum name)
	{
		return _caps.find(name) != _caps.end();
	}
	
	
	cap* Renderpass::removeCapability (GLenum name)
	{
		if (!hasCapability(name)) return nullptr;
		
		std::map<GLenum, cap*>::iterator it = _caps.find(name);
		_caps.erase(it);
		return it->second;
	}
	
	
	void Renderpass::addClearmask (clearmask* clearmask)
	{
		if (hasClearmask(clearmask->field)) return;
		_clearmasks[clearmask->field] = clearmask;
	}
	
	
	bool Renderpass::hasClearmask (GLbitfield name)
	{
		return _clearmasks.find(name) != _clearmasks.end();
	}
	
	
	clearmask* Renderpass::removeClearmask (GLbitfield name)
	{
		if (!hasClearmask(name)) return nullptr;
		
		std::map<GLbitfield, chaosgl::clearmask*>::iterator it = _clearmasks.find(name);
		_clearmasks.erase(it);
		return it->second;
	}
	
	
	void Renderpass::_beforeRender () {};
	
	
	void Renderpass::_afterRender () {};
	
	
	Renderpass::~Renderpass ()
	{
		_clearmasks.clear();
		_caps.clear();
	}
} /* namespace ca */
