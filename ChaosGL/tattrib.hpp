//
//  tattrib.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tattrib_hpp
#define ChaosGL_tattrib_hpp

#include "Bufferable.hpp"
#include <glm/glm.hpp>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>

namespace chaosgl
{
	template<typename T>
	struct tattrib : public virtual Bufferable
	{
	public:
		
		/** Describes its own type */
		typedef tattrib<T> Type;
		
		/** Describes the type of data it holds */
		typedef T VertexType;
		
		
		/** Indicates how to store data */
		GLenum usage = GL_STATIC_DRAW;
		
		
		/**
		 * Creates a new vertex attribute container
		 */
		tattrib () : chaosgl::Bufferable(sizeof(VertexType))
		{
		}
		
		
		/** 
		 * Destroys the attribute
		 */
		virtual ~tattrib () {};
		
		
		virtual void* getData (int index, GLenum target = GL_ARRAY_BUFFER) const
		{
			return &(this->getValue(index, target));
		}
		
		
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
		
		
		/** 
		 * Provides the size of the attribute per vertex
		 */
		long byteSizePerVertex () const
		{
			return sizeof(VertexType);
		}
	};
}

#endif
