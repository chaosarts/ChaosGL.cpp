//
//  Drawable.h
//  ChaosGL
//
//  Created by Fu Lam Diep on 08.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef _ChaosGL_Drawable_h
#define _ChaosGL_Drawable_h

#include "Program.h"

namespace ca
{
	namespace gl
	{
		class Drawable
		{
		public:
			
			/**
			 * Obligated destructor
			 */
			virtual ~Drawable () {};
			
			
			/**
			 * Draws the object with given program
			 */
			virtual void draw (Program* program);
		};
	}
}
#endif /* Drawable_h */
