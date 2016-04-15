//
//  ttriangle.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_ttriangle_hpp
#define ChaosGL_ttriangle_hpp

#include "ttriangle3.hpp"
#include "ttriangle2.hpp"

namespace chaosgl
{
	typedef ttriangle3<float, glm::highp> float_highp_triangle3;
	typedef ttriangle3<float, glm::mediump> float_mediump_triangle3;
	typedef ttriangle3<float, glm::lowp> float_lowp_triangle3;
	
	typedef float_highp_triangle3 highp_triangle3;
	typedef float_mediump_triangle3 mediump_triangle3;
	typedef float_lowp_triangle3 lowp_triangle3;
	
	typedef highp_triangle3 triangle3;
	
	typedef ttriangle2<float, glm::highp> float_highp_triangle2;
	typedef ttriangle2<float, glm::mediump> float_mediump_triangle2;
	typedef ttriangle2<float, glm::lowp> float_lowp_triangle2;
	
	typedef float_highp_triangle2 highp_triangle2;
	typedef float_mediump_triangle2 mediump_triangle2;
	typedef float_lowp_triangle2 lowp_triangle2;
	
	typedef highp_triangle2 triangle2;
}

#endif /* ttriangle_h */
