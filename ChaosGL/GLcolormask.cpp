/*
 * GLcolorbit.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "GLcolormask.h"

namespace ca
{
	namespace gl
	{

		GLcolormask::GLcolormask(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) :
				GLclearmask(GL_COLOR_BUFFER_BIT), red(red), green(green), blue(blue), alpha(alpha) {}

		GLcolormask::GLcolormask(GLclampf value, GLclampf alpha) : GLcolormask(value, value, value, alpha) {}


		GLcolormask::GLcolormask(GLclampf alpha): GLcolormask(0, alpha) {}


		GLcolormask::~GLcolormask()
		{

		}


		void GLcolormask::clear()
		{
			glClearColor(red, green, blue, alpha);
		}

	} /* namespace gl */
} /* namespace ca */
