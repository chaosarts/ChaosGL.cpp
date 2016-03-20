//
//  tquad.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tquad_h
#define ChaosGL_tquad_h

#include <glm/glm.hpp>
#include <glm/mat3x3.hpp>

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct tquad
	{
	public:
		
		/// Describes its own type
		typedef tquad<T> Type;
		
		/// Describes the type of the vector components
		typedef glm::tvec3<T, P> VectorType;
		
		/** Describes the value type of the vector */
		typedef T ValueType;
		
		/** Provides the precision used for glm vec*/
		const glm::precision precision = P;
		
		/// Provides the components of the quadliteral
		union {struct {VectorType a, b, c, d;};};
		
		/// Creates a new quad object with components
		/// @param a The support vector
		/// @param b The reference for the first direction vector of the plane
		/// @param c The reference for the second direction vector of the plane
		/// @param d The reference for the third direction vector of the plane
		tquad (VectorType a, VectorType b, VectorType c, VectorType  d) : a(a), b(b), c(c), d(d)
		{
			const VectorType tu = u();
			const VectorType tv = v();
			const VectorType tw = w();
			
			const glm::tmat3x3<T, P> mat = glm::tmat3x3<T, P>(tu, tv, tw);
			if (glm::determinant(mat) == 0)
				throw "<quad> Components of primitve quad are not coplanar";
			
			if (glm::dot(tu, tv) == 0 && glm::dot(tu, tw) == 0)
				throw "<quad> Points cannot result to a plane.";
		}
		
		
		tquad (const Type &q) : a(q.a), b(q.b), c(q.c), d(q.d) {};
		
		
		virtual ~tquad () {};
		
		
		/// Returns the first direction vector of the quad plane
		VectorType u ()
		{
			return b - a;
		}
		
		
		/// Returns the second direction vector of the quad plane
		VectorType v ()
		{
			return c - a;
		}
		
		
		/// Returns the third direction vector of the quad plane
		VectorType w ()
		{
			return d - a;
		}
		
		
		/// Returns the normal of the quad
		VectorType normal (bool ccw = true)
		{
			const VectorType u = u();
			const VectorType v = v();
			
			if (glm::dot(u, v) == 0) return glm::cross(u, w());
			return glm::cross(u, v);
		}
	};
}

#endif /* tquad_h */
