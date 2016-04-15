//
//  ttexcoord.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_ttexcoord_hpp
#define ChaosGL_ttexcoord_hpp

#include <glm/glm.hpp>
#include "attrib.hpp"
#include "Texture.hpp"

namespace chaosgl
{
	template<typename V>
	struct ttexcoord : public virtual tattrib<V>
	{
	public:
		
		/** Describses its own type */
		typedef ttexcoord<V> Self;
		
		/** Describes the vertex type */
		typedef V VertexType;
		
		
		/** Provides the texture */
		Texture* texture;
		
		
		/** Creates a new ttexture */
		ttexcoord (Texture* texture) : texture(texture) {}
		
		
		/** Destroys the ttexture */
		virtual ~ttexcoord () {};
	};
}

#endif /* ttexcoord_h */
