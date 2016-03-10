//
//  GLattriblocation.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 09.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "GLattriblocation.hpp"

namespace ca
{
	namespace gl
	{
		GLattriblocation::GLattriblocation (GLuint id, const char* name) : id(id), name(name) {}
		
		
		GLattriblocation::~GLattriblocation() {};
		
		
		void GLattriblocation::setEnabled(bool enable)
		{
			if (enable) glEnableVertexAttribArray(id);
			else glDisableVertexAttribArray(id);
		}
		
		
		
	}
}