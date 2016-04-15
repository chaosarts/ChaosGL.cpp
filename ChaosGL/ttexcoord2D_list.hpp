//
//  ttexture2D_list.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 21.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_ttexture2D_list_hpp
#define ChaosGL_ttexture2D_list_hpp

#include <glm/glm.hpp>
#include "tattrib_list.hpp"
#include "ttexture2D.hpp"

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct ttexcoord2D_list : public virtual ttexture2D<T, P>, public virtual tattrib_list<glm::vec3<T, P>>
	{
		
	}
}

#endif /* ttexture2D_list_h */
