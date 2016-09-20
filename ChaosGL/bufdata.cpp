//
//  bufdata.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 19.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "bufdata.hpp"
#include <ChaosCore/ChaosCore.hpp>
#include <cstring>
#ifdef __APPLE__
#include <stdlib.h>
#else
#include <cstdlib>
#endif

namespace chaosgl
{
	bufdata::bufdata (GLsizeiptr size) : begin(malloc(size)), size(size)
	{
		_current = begin;
	}
	
	bufdata::~bufdata ()
	{
		free(begin);
	}
	
	
	void bufdata::push(void *data, GLsizeiptr size)
	{
		if ((char*) begin + this->size <= (char*) _current + size)
		{
			chaos::warn("<bufdata::push> Memory is exhausted");
			return;
		}
		
		std::memcpy(_current, data, size);
		_current = (char*) begin + size;
	}
}