//
//  main.cpp
//  Playground
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <ChaosCore/core.cpp>
#include "attrib.hpp"

using namespace glm;
using namespace ca::core;
using namespace ca::gl;

template<typename T>
struct base
{
public:
	
	int size ();
	
	long byteSize () {
		return sizeof(T);
	}
};


template<>
int base<vec3>::size () {return 3;};


template<typename T>
struct A : public base<T>
{};

int main(int argc, const char * argv[])
{
	tattrib_list<vec3> a = tattrib_list<vec3>();
	
	info("%i", a.size());
	return 0;
}
