//
//  GLattriblocation.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 09.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef _ChaosGL_GLattriblocation_hpp
#define _ChaosGL_GLattriblocation_hpp

#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
	{
		struct GLattriblocation {
		public:
			
			const GLuint id;
			
			const char* const name;
			
			GLattriblocation (GLuint id, const char* name);
			
			~GLattriblocation ();
			
			void setEnabled (bool enable);
			
			
			
		};
	}
}

#endif /* GLattriblocation_hpp */
