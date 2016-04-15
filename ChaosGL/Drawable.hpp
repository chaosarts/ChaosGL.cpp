//
//  Bufferable.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_Drawable_hpp
#define ChaosGL_Drawable_hpp

#include <vector>
#include <OpenGL/OpenGL.h>
#include "Buffer.hpp"

namespace chaosgl
{
	
	class Drawable
	{
	public:
		
		std::vector<Buffer> getBuffers ();
		
		void draw ();
	};
	
}
#endif
