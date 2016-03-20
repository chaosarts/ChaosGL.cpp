//
//  primitiv.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_primitive_hpp_
#define ChaosGL_primitive_hpp_

#include "ttriangle.hpp"
#include "tquad.hpp"

namespace chaosgl
{
	typedef ttriangle<float, glm::highp> highp_triangle;
	typedef highp_triangle triangle;
	
		
	typedef tquad<float, glm::highp> highp_quad;
	typedef highp_quad quad;
}
#endif
