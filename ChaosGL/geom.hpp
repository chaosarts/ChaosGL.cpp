//
//  geom.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_geom_hpp_
#define ChaosGL_geom_hpp_

#include "tgeom.hpp"
#include "tgeom_list.hpp"

namespace chaosgl
{
	typedef tgeom_list<float, glm::lowp> lowp_geom_list;
	typedef tgeom_list<float, glm::mediump> mediump_geom_list;
	typedef tgeom_list<float, glm::highp> highp_geom_list;
	
	typedef lowp_geom_list lowp_geom;
	typedef mediump_geom_list mediump_geom;
	typedef highp_geom_list highp_geom;
	typedef highp_geom geom;
}

#endif
