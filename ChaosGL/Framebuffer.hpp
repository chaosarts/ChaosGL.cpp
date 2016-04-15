//
//  Framebuffer.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_Framebuffer_hpp
#define ChaosGL_Framebuffer_hpp

#include "ChaosGL.hpp"

namespace chaosgl
{
	/**
	 * Class wrapper for framebuffers
	 */
	class Framebuffer
	{
	private:
		
		/** Provides the id of the frame buffer */
		GLuint _id;
		
	public:
		
		/**
		 * Creates a new Framebuffer object
		 */
		Framebuffer ();
		
		
		/**
		 * Destroys a Framebuffer object
		 */
		virtual ~Framebuffer ();
		
		
		/** 
		 * Returns the id
		 */
		GLuint getId ();
		
		
		/**
		 * Binds the framebuffer
		 */
		void bind ();
	};
}

#endif /* Framebuffer_hpp */
