//
//  depthcap.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 18.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "depthtest.hpp"

namespace chaosgl
{	
	depthtest::depthtest(GLenum func) : cap(GL_DEPTH_TEST)
	{
		this->func = func;
	}
	
	
	depthtest::depthtest() : depthtest(GL_LESS)
	{
		
	}
	
	
	void depthtest::_apply() const
	{
		glDepthFunc(func);
	}
}
