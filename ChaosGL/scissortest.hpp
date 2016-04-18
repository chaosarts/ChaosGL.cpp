//
//  scissortest.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 18.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_scissortest_hpp
#define ChaosGL_scissortest_hpp

#include "cap.hpp"

namespace chaosgl
{
	struct scissortest : public virtual cap
	{
	public:
		
		/** 
		 * Specify the lower left corner of the scissor box. 
		 * Initially (0, 0).
		 */
		GLint x, y;
		
		/**
		 * Specify the width and height of the scissor box. When a GL 
		 * context is first attached to a window, width and height are 
		 * set to the dimensions of that window.
		 */
		GLsizei width, height;
		
		/**
		 * Creates a new scissor test capability
		 */
		scissortest (GLint x, GLint y, GLsizei width, GLsizei height);
		
		/**
		 * Creates a new scissor test capability
		 */
		scissortest (GLsizei width, GLsizei height);
	protected:
		
		/** @see chaosgl::cap::_apply */
		virtual void _apply () const;
	};
}
#endif /* ChaosGL_scissortest_hpp */
