/*
 * cap.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "cap.hpp"

namespace ca
{
	namespace gl
	{

		cap::cap(GLenum name, bool enable) : name(name), enabled(enable) {}

		cap::~cap() {}

	} /* namespace gl */
} /* namespace ca */
