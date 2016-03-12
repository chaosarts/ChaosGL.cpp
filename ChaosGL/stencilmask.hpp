/*
 * GLstencilbit.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Glstencilbit_h_
#define _ChaosGL_Glstencilbit_h_

#include "clearmask.hpp"

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
	{

		struct stencilmask : public clearmask
		{
		public:
			GLint stencil;

			stencilmask(GLint stencil = 0);

			virtual ~stencilmask();

			virtual void clear ();
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* GLSTENCILBIT_H_ */
