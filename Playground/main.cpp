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
#include "geom.hpp"

template<typename T>
struct a
{
public:
	virtual void getValue () const = 0;
	
	virtual void count () const = 0;
};


template<typename T>
struct b : public virtual a<T>
{
public:
	virtual void getValue () const {};
};


template<typename T>
struct c : public virtual a<T>
{
public:
	virtual void count () const {}
};

template<typename T>
struct d : public virtual b<T>, public virtual c<T>
{
public:
};

int main(int argc, const char * argv[])
{
	d<float> C = d<float>();
	C.getValue();
//	chaosgl::geom a = chaosgl::geom();
////	a.addValue(glm::vec3());
////	a.addValue(glm::vec3(-1.0, -1.0, 2.0));
//	chaos::info("%i", a.count());
	return 0;
}
