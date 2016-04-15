//
//  glm::tvec.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_string_func_hpp
#define ChaosGL_string_func_hpp

#include <glm/glm.hpp>
#include <cstdio>
#include <string>


namespace std
{	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<bool, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<bool, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<bool, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<bool, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<char, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<char, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<char, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<char, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<unsigned char, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<unsigned char, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<unsigned char, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<unsigned char, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<short, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<short, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<short, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<short, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<unsigned short, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<unsigned short, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<unsigned short, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<unsigned short, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<int, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<int, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<int, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<int, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<unsigned int, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<unsigned int, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<unsigned int, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<unsigned int, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<long, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<long, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<long, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<long, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<unsigned long, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<unsigned long, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<unsigned long, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<unsigned long, P> vec)
	{
		char* s;
		std::sprintf(s, "(%i %i %i %i)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<float, P> vec)
	{
		char* s;
		std::sprintf(s, "(%f)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<float, P> vec)
	{
		char* s;
		std::sprintf(s, "(%f %f)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<float, P> vec)
	{
		char* s;
		std::sprintf(s, "(%f %f %f)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<float, P> vec)
	{
		char* s;
		std::sprintf(s, "(%f %f %f %f)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec1<double, P> vec)
	{
		char* s;
		std::sprintf(s, "(%f)", vec.x);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec2<double, P> vec)
	{
		char* s;
		std::sprintf(s, "(%f %f)", vec.x, vec.y);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec3<double, P> vec)
	{
		char* s;
		std::sprintf(s, "(%f %f %f)", vec.x, vec.y, vec.z);
		return s;
	}
	
	
	template<glm::precision P = glm::highp>
	const char* to_string (glm::tvec4<double, P> vec)
	{
		char* s;
		std::sprintf(s, "(%f %f %f %f)", vec.x, vec.y, vec.z, vec.w);
		return s;
	}
}

#endif /* glm::tvec_hpp */
