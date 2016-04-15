//
//  texcoord.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_texcoord_hpp
#define ChaosGL_texcoord_hpp

#include "ttexcoord.hpp"
#include "ttexcoord2D.hpp"
#include "ttexcoord2D_list.hpp"

namespace chaosgl
{
	typedef ttexcoord2D_list<float, glm::lowp> lowp_texcoord2D_list;
	typedef ttexcoord2D_list<float, glm::mediump> mediump_texcoord2D_list;
	typedef ttexcoord2D_list<float, glm::highp> highp_texcoord2D_list;
	
	typedef lowp_texcoord2D_list lowp_texcoord2D;
	typedef mediump_texcoord2D_list mediump_texcoord2D;
	typedef highp_texcoord2D_list highp_texcoord2D;
	
	typedef highp_texcoord2D texcoord2D;
}

#endif /* texcoord_h */
