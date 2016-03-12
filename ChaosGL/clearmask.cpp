/*
 * GLbitmask.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "clearmask.hpp"

namespace ca
{
	namespace gl
	{
		clearmask::clearmask (GLbitfield field) : field(field) {}
		clearmask::~clearmask() {};

	} /* namespace gl */
} /* namespace ca */

