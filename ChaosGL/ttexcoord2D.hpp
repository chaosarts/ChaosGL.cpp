//
//  ttexcoord2D.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 21.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_ttexcoord2D_hpp
#define ChaosGL_ttexcoord2D_hpp

#include <glm/glm.hpp>
#include "ttexcoord.hpp"

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct ttexcoord2D : public virtual ttexcoord<glm::tvec2<T, P>>
	{
		
	};
}

#endif /* ttexcoord2D_h */
