//
//  rect.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef rect_h
#define rect_h

#include <glm/glm.hpp>
#include "size.hpp"

namespace ca
{
	namespace gl
	{
		template<typename T>
		struct rect
		{
		public:
			typedef rect<T> type;
			typedef T value_type;
			
			glm::tvec2<T> origin;
			gl::size<T> size;
			
			rect (glm::tvec2<T> origin, gl::size<T> size) : origin(origin), size(size) {}
			
			rect (gl::size<T> size) : rect(glm::tvec2<T>(), size) {}
			
			rect (T x, T y, T width, T height) : rect(glm::tvec2<T>(x, y), gl::size<T>(width, height)) {}
			
			rect (T width, T height) : rect(glm::tvec2<T>(), gl::size<T>(width, height)) {}
		};
		
		typedef rect<int> recti;
		typedef rect<float> rectf;
	}
}

#endif /* rect_h */
