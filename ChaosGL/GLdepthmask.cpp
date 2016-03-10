/*
 * GLdepthbit.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "GLdepthmask.h"

namespace ca
{
	namespace gl
	{

		GLdepthmask::GLdepthmask(GLclampd depth) : GLclearmask(GL_DEPTH_BUFFER_BIT), depth(depth) {}


		GLdepthmask::~GLdepthmask() {}


		void GLdepthmask::clear()
		{
			glClearDepth(depth);
		}
	} /* namespace gl */
} /* namespace ca */
