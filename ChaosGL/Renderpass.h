/*
 * Renderpass.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Renderpass_h_
#define _ChaosGL_Renderpass_h_

#include <list>
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include "GLcap.h"
#include "GLclearmask.h"
#include "Program.h"

using namespace std;

namespace ca
{
	namespace gl
	{

		class Renderpass
		{
		private:
			/** Provides the program to use */
			Program* _program;
			
			/** Provides a list of bit masks to apply */
			list<GLclearmask*> _bitmasks;

			/** Provides a list of OpenGL server-side capabilities */
			list<GLcap*> _caps;

		protected:
			virtual void _render () = 0;

			virtual void _beforeRender () = 0;

			virtual void _afterRender () = 0;
		public:
			virtual ~Renderpass();

			void render ();

			void setCapability (GLcap* cap);

			void addBitmask (GLclearmask* bitmask);
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* RENDERER_H_ */
