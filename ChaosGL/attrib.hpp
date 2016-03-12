//
//  attrib.h
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef attrib_h
#define attrib_h

#include <glm/glm.hpp>

using namespace glm;

namespace ca
{
	namespace gl
	{
		template<typename T>
		struct attrib
		{
		public:
			
			/// Provides the data type
			typedef T type;
			
			/// Destroys the attribute
			virtual ~attrib ();
			
			/// Indicates whether the data needs to be normalized (GL_TRUE) or not (GL_FALSE)
			const GLboolean normalized;
			
			/// Returns the attribute value of the vertex at given index
			virtual T operator[] (int index) = 0;
			
			/// Returns the count of attribute values
			virtual int count () = 0;
			
			/// Returns the size of the attribute per vertex (1, 2, 3 or 4)
			virtual int size () const = 0;
			
			/// Provides the size of the attribute per vertex
			long byteSize () const
			{
				return sizeof(T);
			}
		};
	}
}
#endif /* attrib_h */
