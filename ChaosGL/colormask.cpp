/*
 * GLcolorbit.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "colormask.hpp"

namespace chaosgl
{

		colormask::colormask(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) :
				clearmask(GL_COLOR_BUFFER_BIT), red(red), green(green), blue(blue), alpha(alpha) {}

		colormask::colormask(GLclampf value, GLclampf alpha) : colormask(value, value, value, alpha) {}


		colormask::colormask(GLclampf alpha): colormask(0, alpha) {}


		colormask::~colormask()
		{

		}


		void colormask::clear()
		{
			glClearColor(red, green, blue, alpha);
		}
} /* namespace ca */
