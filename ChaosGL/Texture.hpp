//
//  Texture.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_Texture_hpp
#define ChaosGL_Texture_hpp

#include "ChaosGL.hpp"

namespace chaosgl
{
	class Texture
	{
	private:
		
		/** Provides the id of the texture */
		GLuint _id = 0;
		
	public:
		
		/** Provides the texture target */
		const GLenum target;
		
		/** Specifies the level-of-detail number. */
		GLint level = 0;
		
		/** Specifies the number of color components in the texture. */
		GLint internalFormat = GL_RGBA;
		
		/** Provides the size of the texture */
		GLsizei width = 0;
		
		/** Specifies the format of the pixel data. */
		GLenum format = GL_RGBA;
		
		/** Specifies the data type of the pixel data. */
		GLenum type = GL_UNSIGNED_BYTE;
		
		/**
		 * Creates a new Texture
		 * @param target
		 */
		Texture (GLenum target);
		
		
		/**
		 * Destroys the Texture
		 */
		virtual ~Texture ();
		
		
		/**
		 * Returns the id of the texture
		 * @return The generic id of the texture
		 */
		GLuint getId ();
		
		
		/**
		 * Binds th texture
		 */
		void bind ();
		
		
		/**
		 * Sets the pixel data of the texture
		 * @param data
		 */
		virtual void setData (const GLvoid* data) = 0;
		
		
		/**
		 * Sets the value for a paramater for this texture
		 * @param pname The name of the parameter
		 * @param value The value to set
		 */
		void setParam (GLenum pname, GLfloat value);
		
		
		/**
		 * Sets the value for a paramater for this texture
		 * @param pname The name of the parameter
		 * @param value The value to set
		 */
		void setParam (GLenum pname, GLfloat* value);
		
		
		/**
		 * Gets th value for a parameter for this texture
		 * @param pname The name of the parameter to get
		 */
		void getParamf (GLenum pname, GLfloat* value);
		
		
		/**
		 * Sets the value for a paramater for this texture
		 * @param pname The name of the parameter
		 * @param value The value to set
		 */
		void setParam (GLenum pname, GLint value);
		
		
		/**
		 * Sets the value for a paramater for this texture
		 * @param pname The name of the parameter
		 * @param value The value to set
		 */
		void setParam (GLenum pname, GLint* value);
		
		
		/**
		 * Gets th value for a parameter for this texture
		 * @param pname The name of the parameter to get
		 */
		void getParami (GLenum pname, GLint* value);
		
		
		/**
		 * Sets the min filter type
		 * @param value
		 */
		void setMinFilter (GLint value);
		
		
		/**
		 * Returns the single-valued texture minification 
		 * filter, a symbolic constant. The initial value is 
		 * GL_NEAREST_MIPMAP_LINEAR.
		 */
		GLint getMinFilter ();
		
		
		/**
		 * Sets the mag filter type
		 * @param value
		 */
		void setMagFilter (GLint value);
		
		
		/**
		 * Returns the single-valued texture magnification filter, 
		 * a symbolic constant. The initial value is GL_LINEAR.
		 */
		GLint getMagFilter ();
		
		
		/**
		 * Sets the minimum level-of-detail parameter. This floating-point
		 * value limits the selection of the lowest resolution mipmap
		 * (highest mipmap level). The initial value is -1000.
		 * @param value
		 */
		void setMinLod (GLint value);
		
		
		/**
		 * Returns the single-valued texture minimum level-of-detail value. 
		 * The initial value is -1000.
		 */
		GLint getMinLod ();
		
		
		/**
		 * Sets the maximum level-of-detail parameter. This floating-point 
		 * value limits the selection of the lowest resolution mipmap 
		 * (highest mipmap level). The initial value is 1000.
		 * @param value
		 */
		void setMaxLod (GLint value);
		
		
		/**
		 * Returns the single-valued texture maximum level-of-detail value. 
		 * The initial value is 1000.
		 */
		GLint getMaxLod ();
		
		
		/**
		 * Specifies the index of the lowest defined mipmap level. This is 
		 * an integer value. The initial value is 0.
		 * @param value
		 */
		void setBaseLevel (GLint value);
		
		
		/**
		 * Returns the single-valued base texture mipmap level. The initial 
		 * value is 0.
		 */
		GLint getBaseLevel ();
		
		
		/**
		 * Sets the index of the highest defined mipmap level. This is an 
		 * integer value. The initial value is 1000.
		 */
		void setMaxLevel (GLint value);
		
		
		/**
		 * Gets the index of the highest defined mipmap level. This is an
		 * integer value. The initial value is 1000.
		 */
		GLint getMaxLevel ();
		
		
		/**
		 * Sets the value how to wrap the texture in s-direction
		 * @param value
		 */
		void setWrapS (GLint value);
		
		
		/**
		 * Returns the single-valued wrapping function for texture coordinate
		 * s, a symbolic constant. The initial value is GL_REPEAT.
		 */
		GLint getWrapS ();
		
		
		/**
		 * Sets a border color.
		 * @param color
		 */
		void setBorderColor (GLfloat* color);
		
		
		/**
		 * Sets a border color.
		 * @param red
		 * @param green
		 * @param blue
		 * @param alpha
		 */
		void setBorderColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha = 1.0);
		
		
		GLfloat* getBorderColor ();

#ifdef GL_TEXTURE_PRIORITY
		/**
		 * Specifies the texture residence priority of the currently bound 
		 * texture. Permissible values are in the range 0 1.
		 * @param value
		 */
		void setPriority (GLfloat value);
		
		
		/**
		 * Returns the residence priority of the target texture (or the named 
		 * texture bound to it). The initial value is 1.
		 */
		GLfloat getPriority ();
#endif
		
		
		/**
		 * Determines if the generated texture name is a texture or not
		 * @return GL_TRUE if generated name is a texture, else GL_FALSE
		 */
		GLboolean isTexture ();
	};
}

#endif /* Texture_hpp */
