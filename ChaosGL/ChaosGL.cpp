//
//  ChaosGL.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 21.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "ChaosGL.hpp"

namespace chaosgl
{
	bool _initialized = false;
	
	bool init (int argc, const char** argv)
	{
		if (!_initialized) _initialized = true;		
		return _initialized;
	}
}
