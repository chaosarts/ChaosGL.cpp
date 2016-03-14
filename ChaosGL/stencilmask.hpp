/*
 * GLstencilbit.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Glstencilbit_h_
#define ChaosGL_Glstencilbit_h_

#include "clearmask.hpp"

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace chaosgl
{

		struct stencilmask : public clearmask
		{
		public:
			GLint stencil;

			stencilmask(GLint stencil = 0);

			virtual ~stencilmask();

			virtual void clear ();
		};
} /* namespace ca */

#endif /* GLSTENCILBIT_H_ */
