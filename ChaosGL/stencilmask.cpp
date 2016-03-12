/*
 * GLstencilbit.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "stencilmask.hpp"

namespace ca
{
	namespace gl
	{

		stencilmask::stencilmask(GLint stencil) : clearmask(GL_STENCIL_BUFFER_BIT), stencil(stencil) {}


		stencilmask::~stencilmask() {}


		void stencilmask::clear()
		{
			glClearStencil(stencil);
		}

	} /* namespace gl */
} /* namespace ca */
