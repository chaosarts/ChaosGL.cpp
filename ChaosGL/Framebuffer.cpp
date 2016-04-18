//
//  Framebuffer.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Framebuffer.hpp"
#include <ChaosCore/ChaosCore.hpp>

namespace chaosgl
{
	GLuint Framebuffer::getId()
	{
		if (_id == 0)
		{
			glGenFramebuffers(1, &_id);
			if (_id == 0) chaos::warn("<Framebuffer> No id generated.");
		}
		
		return _id;
	}
	
	
	
}