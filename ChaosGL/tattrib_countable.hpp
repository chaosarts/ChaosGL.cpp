//
//  tattrib_countable.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tattrib_countable_h
#define ChaosGL_tattrib_countable_h

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
		
		typedef tattrib_countable<T> Type;
		
		typedef T VertexType;
		
		/// Returns the count of value to buffer, depending on passed target
		virtual int count (GLenum target = GL_ARRAY_BUFFER) const = 0;
		
		/// Returns the according index list for glDrawElements
		virtual std::vector<int> getIndexList () const = 0;
		
		/// Returns the total amount of memory space for the attribute values
		long totalByteSize (GLenum target = GL_ARRAY_BUFFER) const
		{
			return count(target) * this->byteSizePerVertex();
		}
	};
}

#endif
