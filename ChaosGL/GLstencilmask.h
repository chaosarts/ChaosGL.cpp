/*
 * GLstencilbit.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Glstencilbit_h_
#define _ChaosGL_Glstencilbit_h_

#include "GLclearmask.h"

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
	{

		struct GLstencilmask : public GLclearmask
		{
		public:
			GLint stencil;

			GLstencilmask(GLint stencil = 0);

			virtual ~GLstencilmask();

			virtual void clear ();
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* GLSTENCILBIT_H_ */
