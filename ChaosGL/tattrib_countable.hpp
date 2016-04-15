//
//  tattrib_countable.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tattrib_countable_hpp
#define ChaosGL_tattrib_countable_hpp

#include <vector>

#include <OpenGL/OpenGL.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>

#include "tattrib.hpp"

namespace chaosgl
{
	/// Base struct to for countable attribute values
	template<typename T>
	struct tattrib_countable : public virtual tattrib<T>
	{
	public:
		
		/** Describes its own type */
		typedef tattrib_countable<T> Type;
		
		/** Describes the type of data it holds */
		typedef T VertexType;
		
		
		/** 
		 * Returns the count of value to buffer, depending on passed target
		 * @param target: Indicates for which buffer target to count
		 * @return The count of vertex attribute values
		 */
		virtual int count (GLenum target = GL_ARRAY_BUFFER) const = 0;
		
		
		/**
		 * Returns the index of the vertex from the vertex list.
		 * @param vertex
		 * @return The index of the vertex
		 */
		virtual int indexOf (VertexType vertex) const = 0;
		
		
		/**
		 * Returns the according index list for glDrawElements
		 */
		virtual std::vector<int> getIndexList () const = 0;
		
		
		/** 
		 * Returns the total amount of memory space for the attribute values
		 */
		long totalByteSize (GLenum target = GL_ARRAY_BUFFER) const
		{
			return count(target) * this->byteSizePerVertex();
		}
	};
}

#endif
