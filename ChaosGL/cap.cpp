/*
 * cap.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "cap.hpp"

namespace chaosgl
{
	cap::cap (GLenum name) : name(name) {}
	
	cap::~cap () {}
	
	
	GLenum cap::apply () const
	{
		glEnable(name);
		_apply();
		return glGetError();
	}
	
	
	GLenum cap::revert () const
	{
		glDisable(name);
		return glGetError();
	}
} /* namespace ca */
