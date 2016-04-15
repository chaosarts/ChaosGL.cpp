//
//  tbn.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tbasis3_hpp
#define ChaosGL_tbasis3_hpp

#include "triangle.hpp"
#include <glm/glm.hpp>

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct tbasis3
	{
	public:
		
		/** Describes its own type */
		typedef tbasis3<T, P> Type;
		
		/** Describes the vector type it holds */
		typedef glm::tvec3<T, P> VectorType;
		
		/** Describes the value type of the vector */
		typedef T ValueType;
		
		typedef glm::tvec3<T, P> vec3;
		typedef glm::tvec2<T, P> vec2;
		
		
		/** Provides the componentns of the tangent space */
		const union {
			
			struct {
				/** Provides the x axis of the basis */
				VectorType x;
				
				/** Provides the y axis of the basis */
				VectorType y;
				
				/** Provides the z axis of the basis */
				VectorType z;
			};
			
			struct {
				/** Provides the tangent of the tangent space. Same as x */
				VectorType tangent;
				
				/** Provides the bitangent of the tangent space. Same as y */
				VectorType bitangent;
				
				/** Provides the normal of the tangent space. Same as z */
				VectorType normal;
			};
			
			struct {
				/** Provides the tangent of the tangent space */
				VectorType t;
				
				/** Provides the bitangent of the tangent space */
				VectorType b;
				
				/** Provides the normal of the tangent space */
				VectorType n;
			};
		};
		
		
		/**
		 * Creates the standard basis
		 */
		tbasis3 () : x(VectorType(1, 0, 0)), y(VectorType(0, 1, 0)), z(VectorType(0, 0, 1)) {}
		
		
		/**
		 * Creates a new vec3 basis
		 * @param x: The x asix of the basis
		 * @param y: The y asix of the basis
		 * @param z: The z asix of the basis
		 */
		tbasis3 (VectorType x, VectorType y, VectorType z) : x(x), y(y), z(z) {}
		
		
		/**
		 * Creates new tvec3 basis by coping from another
		 * @param basis: The basis to copy from
		 */
		tbasis3 (const Type &basis) : x(basis.x), y(basis.y), z(basis.z) {}
		
		
		/**
		 * Destroys the basis
		 */
		virtual ~tbasis3 () {};
		
	private:
		static glm::tmat3x2<T, P> _resolve (triangle3 positions, triangle2 texcoords)
		{
			const vec3 q1 = positions.u();
			const vec3 q2 = positions.v();
			const vec2 d1 = texcoords.u();
			const vec2 d2 = texcoords.v();
			
			const T mul = 1 / (d1.s * d2.t - d1.t * d2.s);
			const glm::tmat2x2<T, P> I(mul * d2.t, -(mul * d2.s), -(mul * d1.t), mul * d1.s);
			const glm::tmat3x2<T, P> Q(q1.x, q2.x, q1.y, q2.y, q1.z, q2.z);
			
			return I * Q;
		}
	};
}

#endif /* tbasis3 */
