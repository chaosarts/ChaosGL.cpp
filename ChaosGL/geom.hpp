//
//  geom.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_geom_hpp_
#define ChaosGL_geom_hpp_

#include <vector>
#include <glm/glm.hpp>
#include "attrib.hpp"
#include "primitive.hpp"

namespace ca
{
	namespace gl
	{
		template<typename T, glm::precision P = glm::defaultp>
		struct tgeom : tattib_list<vec3<T, P>
		{
		public:
			t_triangle<T, P> getTriangle (int index)
			{
				
			}
		};
	}
}
#endif /* geom_hpp */
