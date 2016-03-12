/*
 * GLdepthbit.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "depthmask.hpp"

namespace ca
{
	namespace gl
	{

		depthmask::depthmask(GLclampd depth) : clearmask(GL_DEPTH_BUFFER_BIT), depth(depth) {}


		depthmask::~depthmask() {}


		void depthmask::clear()
		{
			glClearDepth(depth);
		}
	} /* namespace gl */
} /* namespace ca */
