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
		
		typedef tattrib<T> type;
		
		/// Provides the data type
		typedef T value_type;
		
		
		/// Destroys the attribute
		virtual ~tattrib () {};
		
		
		/// Returns the value at givn index for the sepcified target buffer
		virtual T getValue (int index, GLenum target = GL_ARRAY_BUFFER) const = 0;
		
		
		/// Returns the size of the attribute per vertex (1, 2, 3 or 4)
		int size () const
		{
			return element_count(T());
		}
		
		
		/// Provides the size of the attribute per vertex
		long byteSizePerVertex () const
		{
			return sizeof(T);
		}
	};
}

#endif
