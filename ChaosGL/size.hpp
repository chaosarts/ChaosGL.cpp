//
//  GLsize.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_size_hpp_
#define ChaosGL_size_hpp_

namespace chaosgl
{
		template<typename T, glm::precision P = glm::defaultp>
		struct t_size
		{
		public:
			
			/// Describes its own type
			typedef t_size<T, P> type;
			
			/// Describes the data type of the values width and height
			typedef T value_type;
			
			/// Provides the width component of the size
			T width;
			
			/// Provides the height component of the size
			T height;
			
			
			/// Creates a new size object
			t_size (T width, T height) : width(width), height(height) {}
			
			
			/// Copy constructor
			t_size (const t_size<T, P> &s) : t_size(s.width, s.height) {}
			
			
			/// Destructor
			virtual ~t_size () {}
		};
		
		
		typedef t_size<float, glm::highp> highp_size;
		typedef highp_size size;
	}
}
#endif /* GLsize_hpp */
