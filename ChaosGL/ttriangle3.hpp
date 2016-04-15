//
//  ttriangle.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_ttriangle_hpp
#define ChaosGL_ttriangle_hpp

#include <glm/glm.hpp>

namespace chaosgl
{
	template<typename VectorType>
	struct ttriangle3
	{
	public:
		
		/** Describes its own type */
		typedef ttriangle<VectorType> Type;
	};
}

#endif /* ttriangle_h */
