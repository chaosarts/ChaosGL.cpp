/*
 * GLstencilbit.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "GLstencilmask.h"

namespace ca
{
	namespace gl
	{

		GLstencilmask::GLstencilmask(GLint stencil) : GLclearmask(GL_STENCIL_BUFFER_BIT), stencil(stencil) {}


		GLstencilmask::~GLstencilmask() {}


		void GLstencilmask::clear()
		{
			glClearStencil(stencil);
		}

	} /* namespace gl */
} /* namespace ca */
