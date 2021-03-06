//
//  attrib_func.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 13.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_attrib_func_hpp
#define ChaosGL_attrib_func_hpp

#include <glm/glm.hpp>
#include "tattrib.hpp"

namespace chaosgl
{
	
	template<typename T>
	void* contribute (void* data, tattrib<T>* attribute, int index, GLenum target = GL_ARRAY_BUFFER)
	{
		T* ptr = (T*) data;
		*ptr = attribute->getValue(index, target);
		ptr = ptr + 1;
		return (void*) ptr;
	}
	
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
