//
//  Texture2D.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 21.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_Texture2D_hpp
#define ChaosGL_Texture2D_hpp

#include "Texture.hpp"

namespace chaosgl
{
	class Texture2D : public virtual Texture
	{
	public:
				
		/** Specifies the height of the texture image */
		GLsizei height = 0;
		
		
		/**
		 * Creates a new Texture2D
		 */
		Texture2D ();
		
		
		/**
		 * Destroys the Txture2D
		 */
		virtual ~Texture2D ();
		
		
		/**
		 * Sets the data for the texture
		 */
		virtual void setData (const GLvoid* data);
		
		/**
		 * Sets the value how to wrap the texture in t-direction
		 * @param value
		 */
		void setWrapT (GLint value);
		
		
		/**
		 * Gets the value how to wrap the texture in t-direction
		 */
		GLint getWrapT ();
	};
}

#endif /* Texture2D_hpp */
