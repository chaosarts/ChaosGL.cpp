//
//  ttriangle.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_ttriangle_h
#define ChaosGL_ttriangle_h

#include <glm/glm.hpp>

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct ttriangle
	{
	public:
		
		/** Describes its own type */
		typedef ttriangle<T, P> Self;
		
		/** Describes the vector type it holds */
		typedef glm::tvec3<T, P> VectorType;
		
		/** Describes the value type of the vector */
		typedef T ValueType;
		
		
		/** Provides the points of the t_triangle */
		union {struct {const VectorType a, b, c;};};
		
		/** Provides the precision */
		const glm::precision precision = P;
		
		
		/**
		 * Creates a new t_triangle with given points
		 * @param a The support vector
		 * @param b The reference point for the first direction vector if t_triangle is interpreted as ccw
		 * @param c The reference point for the second direction vector if t_triangle is interpreted as ccw
		 */
		ttriangle (VectorType a, VectorType b, VectorType c) : a(a), b(b), c(c)
		{
			if (glm::dot(u(), v()) == 0.0)
				throw "<triangle> Passed points are linearly dependent";
		}
		
		
		/**
		 * Copy constructor
		 * @param t The t_triangle to copy from
		 */
		ttriangle (const Self &t) : a(t.a), b(t.b), c(t.c) {}
		
		
		/**
		 * Destructor
		 */
		virtual ~ttriangle () {}
		
		
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
		
		
		/**
		 * Depending on the ccw flag (counter clock wise) this method
		 * returns the according normal.
		 */
		VectorType normal (bool ccw = true) const
		{
			if (ccw) return glm::cross(u(), v());
			else return glm::cross(v(), u());
		}
	};
}

#endif /* ttriangle_h */
