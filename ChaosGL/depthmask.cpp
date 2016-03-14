/*
 * GLdepthbit.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "depthmask.hpp"

namespace chaosgl
{
	depthmask::depthmask(GLclampd depth) : clearmask(GL_DEPTH_BUFFER_BIT), depth(depth) {}
	
	
	depthmask::~depthmask() {}
	
	
	void depthmask::clear()
	{
		glClearDepth(depth);
	}
} /* namespace ca */
