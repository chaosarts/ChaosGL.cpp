//
//  main.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 21.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include <cstdio>
#include <ChaosCore/ChaosCore.hpp>
#include <ChaosGL/geom.hpp>
#include <ChaosGL/basis.hpp>

class A
{
public:
	A () {}
	~A ()
	{
		fprintf(stdout, "Destruct A.");
	}
};

class B: private A
{
public:
	B () {}
	virtual ~B ()
	{
		fprintf(stdout, "Destruct B.");
	}
};


void test ()
{
	B b = B();
}

int main (int argc, const char** argv)
{
	test();
	return 0;
}
