/*
 * Renderpass.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "Renderpass.h"

namespace ca
{
	namespace gl
	{
		Renderpass::~Renderpass() {}


		void Renderpass::render ()
		{
			{
				list<GLclearmask*>::iterator it = _bitmasks.begin();
				GLbitfield mask = 0;

				while (it != _bitmasks.end())
				{
					(*it)->clear();
					mask = mask | (*it)->field;
				}

				glClear(mask);
			}

			{
				list<GLcap*>::iterator it = _caps.begin();
				while (it != _caps.end())
				{
					if ((*it)->enabled) glEnable((*it)->name);
					else glDisable((*it)->name);
				}
			}

			_beforeRender();
			_render();
			_afterRender();
		}


		void Renderpass::setCapability (GLcap* cap)
		{
			_caps.push_back(cap);
		}


		void Renderpass::addBitmask(GLclearmask* bitmask)
		{
			_bitmasks.push_back(bitmask);
		}

	} /* namespace gl */
} /* namespace ca */
