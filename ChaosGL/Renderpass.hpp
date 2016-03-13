/*
 * Renderpass.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Renderpass_h_
#define ChaosGL_Renderpass_h_

#include <list>
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include "cap.hpp"
#include "clearmask.hpp"
#include "Program.hpp"

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
			list<clearmask*> _bitmasks;

			/** Provides a list of OpenGL server-side capabilities */
			list<cap*> _caps;

		protected:
			virtual void _render () = 0;

			virtual void _beforeRender () = 0;

			virtual void _afterRender () = 0;
		public:
			virtual ~Renderpass();

			void render ();

			void setCapability (cap* cap);

			void addBitmask (clearmask* bitmask);
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* RENDERER_H_ */
