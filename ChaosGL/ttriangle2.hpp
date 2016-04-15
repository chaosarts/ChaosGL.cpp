//
//  ttriangle2.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_ttriangle2_hpp
#define ChaosGL_ttriangle2_hpp

#include <glm/glm.hpp>

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct ttriangle2
	{
	public:
		
		/** Describes its own type */
		typedef ttriangle2<T, P> Self;
		
		/** Describes the vector type it holds */
		typedef glm::tvec2<T, P> VectorType;
		
		/** Describes the value type of the vector */
		typedef T ValueType;
		
		
		/** Provides the points of the t_triangle */
		union {
			struct {const VectorType a, b, c;};
			struct {const VectorType p0, p1, p2;};
		};
		
		/** Provides the precision */
		const glm::precision precision = P;
		
		
		/**
		 * Creates a new t_triangle with given points
		 * @param a The support vector
		 * @param b The reference point for the first direction vector if t_triangle is interpreted as ccw
		 * @param c The reference point for the second direction vector if t_triangle is interpreted as ccw
		 */
		ttriangle2 (VectorType a, VectorType b, VectorType c) : a(a), b(b), c(c)
		{
			if (glm::dot(u(), v()) == 0.0)
				throw "<triangle> Passed points are linearly dependent";
		}
		
		
		/**
		 * Copy constructor
		 * @param t The t_triangle to copy from
		 */
		ttriangle2 (const Self &t) : a(t.a), b(t.b), c(t.c) {}
		
		
		/**
		 * Destructor
		 */
		virtual ~ttriangle2 () {}
		
		
		/**
		 * Returns the direction vector with a and b
		 * @return The direction vector
		 */
		VectorType u () const
		{
			return b - a;
		}
		
		
		/**
		 * Returns the direction vector with a and c
		 * @return The direction vector
		 */
		VectorType v () const
		{
			return c - a;
		}
	};
}
#endif /* ttriangle2_h */
