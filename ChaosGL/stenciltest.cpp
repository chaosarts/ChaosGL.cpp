//
//  stenciltest.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 18.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "stenciltest.hpp"
#include <climits>

namespace chaosgl
{
	stenciltest::stenciltest () : stenciltest(GL_ALWAYS, 0, 1, GL_KEEP, GL_KEEP, GL_KEEP)
	{
		
	}
	
	
	stenciltest::stenciltest (GLenum func, GLint ref, GLuint mask, GLenum sfail, GLenum dpfail, GLenum dppass) : cap(GL_STENCIL_TEST)
	{
		this->func = func;
		this->ref = ref;
		this->mask = mask;
		this->sfail = sfail;
		this->dpfail = dpfail;
		this->dppass = dppass;
	}
	
	
	void stenciltest::_apply() const
	{
		glEnable(name);
		glStencilFunc(func, ref, mask);
		glStencilOp(sfail, dpfail, dppass);
	}
}