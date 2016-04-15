//
//  tbn.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tbasis3_hpp
#define ChaosGL_tbasis3_hpp

#include <glm/glm.hpp>
#include "ttriangle.hpp"

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct tbasis3
	{
	public:
		/** Describes its own type */
		typedef tbasis3<T, P> Type;
		
		/** Describes the vector type it holds */
		typedef glm::tvec3<T, P> VectorType3;
		
		/** Describes the vector type it holds */
		typedef glm::tvec2<T, P> VectorType2;
		
		/** Describes the value type of the vector */
		typedef T ValueType;
		
		/** Describes the triangle type for 3d */
		typedef ttriangle3<T, P> triangle3;
		
		/** Describes the triangle type for 2d */
		typedef ttriangle2<T, P> triangle2;
		
		/** Provides the componentns of the tangent space */
		const union {
			
			struct {
				/** Provides the x axis of the basis */
				VectorType3 x;
				
				/** Provides the y axis of the basis */
				VectorType3 y;
				
				/** Provides the z axis of the basis */
				VectorType3 z;
			};
			
			struct {
				/** Provides the tangent of the tangent space. Same as x */
				VectorType3 tangent;
				
				/** Provides the bitangent of the tangent space. Same as y */
				VectorType3 bitangent;
				
				/** Provides the normal of the tangent space. Same as z */
				VectorType3 normal;
			};
			
			struct {
				/** Provides the tangent of the tangent space */
				VectorType3 t;
				
				/** Provides the bitangent of the tangent space */
				VectorType3 b;
				
				/** Provides the normal of the tangent space */
				VectorType3 n;
			};
		};
		
		
		static Type create (triangle3 posTriangle, triangle2 texTriangle)
		{
			VectorType3 tangent, bitangent, normal;
			return Type(tangent, bitangent, posTriangle.normal());
		}
		
		
		tbasis3 (VectorType3 x, VectorType3 y, VectorType3 z) :
			x(x), y(y), z(z) {}
		
		virtual ~tbasis3 () {};
	};
	
	
	typedef tbasis3<float, glm::highp> float_highp_tbn;
	typedef tbasis3<float, glm::mediump> float_mediump_tbn;
	typedef tbasis3<float, glm::lowp> float_lowp_tbn;
	
	typedef float_highp_tbn highp_tbn;
	typedef float_mediump_tbn mediump_tbn;
	typedef float_lowp_tbn lowp_tbn;
	
	typedef highp_tbn tbn;
}

#endif /* tbn_h */
