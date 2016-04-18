//
//  scissortest.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 18.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "scissortest.hpp"


namespace chaosgl
{
	scissortest::scissortest (GLint x, GLint y, GLsizei width, GLsizei height) :
		chaosgl::cap(GL_SCISSOR_TEST)
	{
		
	}
	
	
	scissortest::scissortest (GLsizei width, GLsizei height) : scissortest (0, 0, width, height)
	{
		
	}
}