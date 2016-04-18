//
//  stenciltest.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 18.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_stenciltest_hpp
#define ChaosGL_stenciltest_hpp

#include "cap.hpp"

namespace chaosgl
{
	struct stenciltest : public virtual cap
	{
	public:
		
		/**
		 * Specifies the test function. Eight symbolic constants are valid: GL_NEVER, 
		 * GL_LESS, GL_LEQUAL, GL_GREATER, GL_GEQUAL, GL_EQUAL, GL_NOTEQUAL, and GL_ALWAYS. 
		 * The initial value is GL_ALWAYS.
		 */
		GLenum func;
		
		/**
		 * Specifies the reference value for the stencil test. ref is clamped to the range 
		 * 0 2 n - 1 , where n is the number of bitplanes in the stencil buffer. 
		 * The initial value is 0.
		 */
		GLint ref;
		
		/**
		 * Specifies a mask that is ANDed with both the reference value and the stored 
		 * stencil value when the test is done. The initial value is all 1's.
		 */
		GLuint mask;
		
		/**
		 * Specifies the action to take when the stencil test fails. Eight symbolic 
		 * constants are accepted: GL_KEEP, GL_ZERO, GL_REPLACE, GL_INCR, GL_INCR_WRAP, 
		 * GL_DECR, GL_DECR_WRAP, and GL_INVERT. The initial value is GL_KEEP.
		 */
		GLenum sfail;
		
		/**
		 * Specifies the stencil action when the stencil test passes, but the depth 
		 * test fails. dpfail accepts the same symbolic constants as sfail. The initial 
		 * value is GL_KEEP.
		 */
		GLenum dpfail;
		
		/**
		 * Specifies the stencil action when both the stencil test and the depth test 
		 * pass, or when the stencil test passes and either there is no depth buffer 
		 * or depth testing is not enabled. dppass accepts the same symbolic constants 
		 * as sfail. The initial value is GL_KEEP.
		 */
		GLenum dppass;
		
		
		/**
		 * Creates a new stencil test capability
		 * @param func: Specifies the test function
		 * @param ref: Specifies the reference value
		 * @param mask: Specifies a mask that is ANDed
		 * @param sfail: Specifies the action to take when the stencil test fails
		 * @param dpfail: Specifies the stencil action when the stencil test passes
		 * @param dppass: Specifies the stencil action when both the stencil test and the depth test pass
		 */
		stenciltest (GLenum func, GLint ref, GLuint mask, GLenum sfail, GLenum dpfail, GLenum dppass);
		
		/**
		 * Creates a new stencil test capability with default values
		 */
		stenciltest ();
		
	protected:
		
		/** @see chaosgl::cap::_apply() */
		void _apply () const;
	};
}

#endif /* stenciltest_hpp */
