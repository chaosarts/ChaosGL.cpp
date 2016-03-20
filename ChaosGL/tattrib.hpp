//
//  tattrib.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tattrib_h
#define ChaosGL_tattrib_h

#include <glm/glm.hpp>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>

namespace chaosgl
{
	template<typename T>
	struct tattrib
	{
	public:
		
		typedef tattrib<T> Type;
		
		/// Provides the data type
		typedef T VertexType;
	
	public:
		
		/**
		 * Indicates how to store data
		 */
		GLenum usage = GL_STATIC_DRAW;
		
		
		/** 
		 * Destroys the attribute
		 */
		virtual ~tattrib () {};
		
		
		/** 
		 * Returns the value at givn index for the sepcified target buffer
		 * @return The value at given index
		 */
		virtual VertexType getValue (int index, GLenum target = GL_ARRAY_BUFFER) const = 0;
		
		
		/**
		 * Returns the size of the attribute per vertex (1, 2, 3 or 4)
		 */
		int size () const
		{
			return element_count(VertexType());
		}
		
		
		/// Provides the size of the attribute per vertex
		long byteSizePerVertex () const
		{
			return sizeof(VertexType);
		}
	};
}

#endif
