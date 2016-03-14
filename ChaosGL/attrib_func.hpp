//
//  attrib_func.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 13.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_attrib_func_hpp_
#define ChaosGL_attrib_func_hpp_

#include <glm/glm.hpp>

namespace chaosgl
{
	template<typename T>
	int element_count (T value)
	{
		return 1;
	}
	
	
	template<typename T, glm::precision P = glm::defaultp>
	int element_count (glm::tvec1<T, P> vec = glm::tvec1<T, P> ())
	{
		return 1;
	}
	
	
	template<typename T, glm::precision P = glm::defaultp>
	int element_count (glm::tvec2<T, P> vec = glm::tvec2<T, P> ())
	{
		return 2;
	}
	
	
	template<typename T, glm::precision P = glm::defaultp>
	int element_count (glm::tvec3<T, P> vec = glm::tvec3<T, P> ())
	{
		return 3;
	}
	
	
	template<typename T, glm::precision P = glm::defaultp>
	int element_count (glm::tvec4<T, P> vec = glm::tvec4<T, P> ())
	{
		return 4;
	}
}

#endif
