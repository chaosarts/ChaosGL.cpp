//
//  tattrib_loop.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tattrib_loop_h
#define ChaosGL_tattrib_loop_h

#include <vector>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include "tattrib.hpp"

namespace chaosgl
{
	///
	template<typename T>
	struct tattrib_loop : public virtual tattrib<T>
	{
	private:
		
		/// Provides the single value, which will be passed for any index
		std::vector<T> _values;
		
	public:
		
		/// Attribute loop needs at least one value
		tattrib_loop (T value)
		{
			addValue(value);
		}
		
		/// Destructor
		virtual ~tattrib_loop () {}
		
		
		void add (T value)
		{
			_values.push_back(value);
		}
		
		
		///
		T getValue (int index, GLenum target = GL_ARRAY_BUFFER)
		{
			return _values[index % _values.size()];
		}
	};
}
#endif
