/*
 * GLcap.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "GLcap.h"

namespace ca
{
	namespace gl
	{

		GLcap::GLcap(GLenum name, bool enable) : name(name), enabled(enable) {}

		GLcap::~GLcap() {}

	} /* namespace gl */
} /* namespace ca */
