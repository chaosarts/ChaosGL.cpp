/*
 * GLbitmask.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "GLclearmask.h"

namespace ca
{
	namespace gl
	{

		GLclearmask::GLclearmask (GLbitfield field) : field(field) {}
		GLclearmask::~GLclearmask() {};

	} /* namespace gl */
} /* namespace ca */

