/*
 * Renderpass.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "Renderpass.hpp"
#include "cap.hpp"
#include "clearmask.hpp"
#include "Program.hpp"

namespace chaosgl
{
		Renderpass::~Renderpass() {}


		void Renderpass::render ()
		{
			{
				std::list<clearmask*>::iterator it = _bitmasks.begin();
				GLbitfield mask = 0;

				while (it != _bitmasks.end())
				{
					(*it)->clear();
					mask = mask | (*it)->field;
				}

				glClear(mask);
			}

			{
				std::list<cap*>::iterator it = _caps.begin();
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


		void Renderpass::setCapability (cap* cap)
		{
			_caps.push_back(cap);
		}


		void Renderpass::addBitmask(clearmask* bitmask)
		{
			_bitmasks.push_back(bitmask);
		}
} /* namespace ca */
