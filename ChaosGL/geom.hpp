//
//  geom.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_geom_hpp
#define ChaosGL_geom_hpp

#include "tgeom.hpp"
#include "tgeom_list.hpp"

namespace chaosgl
{
	typedef tgeom<float, glm::lowp> float_lowp_geom;
	typedef tgeom<float, glm::mediump> float_mediump_geom;
	typedef tgeom<float, glm::highp> float_highp_geom;
	typedef tgeom<float, glm::defaultp> float_geom;
	
	typedef float_lowp_geom lowp_geom;
	typedef float_mediump_geom mediump_geom;
	typedef float_highp_geom highp_geom;
	typedef float_geom geom;
	
	typedef tgeom_list<float, glm::lowp> float_lowp_geom_list;
	typedef tgeom_list<float, glm::mediump> float_mediump_geom_list;
	typedef tgeom_list<float, glm::highp> float_highp_geom_list;
	typedef tgeom_list<float, glm::defaultp> float_geom_list;
	
	typedef float_lowp_geom_list lowp_geom_list;
	typedef float_mediump_geom_list mediump_geom_list;
	typedef float_highp_geom_list highp_geom_list;
	typedef float_geom_list geom_list;
}

#endif
