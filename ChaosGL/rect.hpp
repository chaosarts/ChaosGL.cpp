//
//  rect.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_rect_hpp_
#define ChaosGL_rect_hpp_

#include <glm/glm.hpp>
#include "size.hpp"

namespace chaosgl
{
		template<typename T, glm::precision P = glm::defaultp>
		struct t_rect
		{
		public:
			
			/// Describes its own type
			typedef t_rect<T, P> type;
			
			/// Describes the type of the elements of the generic members origin and size
			typedef T value_type;
			
			/// Provides the origin of the rectangle
			glm::tvec2<T, P> origin;
			
			/// Provides the size with width and height of the rectangle
			gl::t_size<T, P> size;
			
			
			/// Constructs the rect by passing origin and size objects
			t_rect (glm::tvec2<T, P> origin, gl::t_size<T, P> size) : origin(origin), size(size) {}
			
			
			/// Constructs the rect by passing a size objects and implictly set origin to zero
			t_rect (gl::t_size<T, P> size) : t_rect(glm::tvec2<T, P>(0, 0), size) {}
			
			
			/// Constructs the rect with components of the origin and size
			t_rect (T x, T y, T width, T height) : t_rect(glm::tvec2<T, P>(x, y), gl::size<T, P>(width, height)) {}
			
			
			/// Constructs the rect with comoponents of size
			t_rect (T width, T height) : t_rect(glm::tvec2<T, P>(), gl::t_size<T, P>(width, height)) {}
			
			
			/// Copy constructor
			t_rect (const t_rect& r) : t_rect(r.origin, r.size) {}
			
			
			/// Destructor
			virtual ~t_rect () {};
		};
		
		typedef t_rect<float, glm::highp> highp_rect;
		typedef highp_rect rect;
	}
}

#endif /* rect_h */
