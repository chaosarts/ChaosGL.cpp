//
//  basis.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 15.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_basis_hpp
#define ChaosGL_basis_hpp

#include "tbasis3.hpp"
#include "basis_func.hpp"

namespace chaosgl
{
	typedef tbasis3<float, glm::highp> float_highp_basis3;
	typedef tbasis3<float, glm::mediump> float_mediump_basis3;
	typedef tbasis3<float, glm::lowp> float_lowp_basis3;
	
	typedef float_highp_basis3 highp_basis3;
	typedef float_mediump_basis3 mediump_basis3;
	typedef float_lowp_basis3 lowp_basis3;
	
	typedef highp_basis3 basis3;
}

#endif /* basis_h */
