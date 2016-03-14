//
//  primitiv.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_primitive_hpp_
#define ChaosGL_primitive_hpp_

#include <glm/glm.hpp>
#include <glm/mat3x3.hpp>

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct t_triangle
	{
	public:
		/// Provides the points of the t_triangle
		union {struct {const glm::tvec3<T, P> a, b, c;};};
		
		
		/// Creates a new t_triangle with given points
		/// @param a The support vector
		/// @param b The reference point for the first direction vector if t_triangle is interpreted as ccw
		/// @param c The reference point for the second direction vector if t_triangle is interpreted as ccw
		t_triangle (glm::tvec3<T, P> a, glm::tvec3<T, P> b, glm::tvec3<T, P> c) : a(a), b(b), c(c)
		{
			if (glm::dot(u(), v()) == 0)
				throw "<triangle> Passed points are linearly dependent";
		}
		
		
		/// Copy constructor
		/// @param t The t_triangle to copy from
		t_triangle (const t_triangle<T, P> &t) : a(t.a), b(t.b), c(t.c) {}
		
		
		/// Destructor
		virtual ~t_triangle () {}
		
		
		/// Returns the direction vector with a and b
		/// @return The direction vector
		glm::tvec3<T, P> u () const
		{
			return b - a;
		}
		
		
		/// Returns the direction vector with a and c
		/// @return The direction vector
		glm::tvec3<T, P> v () const
		{
			return c - a;
		}
		
		
		/// Depending on the ccw flag (counter clock wise) this method
		/// returns the according normal.
		glm::tvec3<T, P> normal (bool ccw = true) const
		{
			if (ccw) return glm::cross(u(), v());
			else return glm::cross(v(), u());
		}
	};
	
	
	typedef t_triangle<float, glm::highp> highp_triangle;
	typedef highp_triangle triangle;
	
	
	template<typename T, glm::precision P = glm::defaultp>
	struct t_quad
	{
	public:
		
		/// Describes its own type
		typedef t_quad<T> type;
		
		/// Describes the type of the vector components
		typedef T value_type;
		
		/// Provides the components of the quadliteral
		union {struct {glm::tvec3<T, P> a, b, c, d;};};
		
		/// Creates a new quad object with components
		/// @param a The support vector
		/// @param b The reference for the first direction vector of the plane
		/// @param c The reference for the second direction vector of the plane
		/// @param d The reference for the third direction vector of the plane
		t_quad (value_type a, value_type b, value_type c, value_type  d) : a(a), b(b), c(c), d(d)
		{
			const glm::tvec3<T, P> u = u();
			const glm::tvec3<T, P> v = v();
			const glm::tvec3<T, P> w = w();
			
			const glm::tmat3x3<T, P> mat = glm::tmat3x3<T, P>(u, v, w);
			if (glm::determinant(mat) == 0)
				throw "<quad> Components of primitve quad are not coplanar";
			
			if (glm::dot(u, v) == 0 && glm::dot(u, w) == 0)
				throw "<quad> Points cannot result to a plane.";
		}
		
		
		/// Returns the first direction vector of the quad plane
		glm::tvec3<T, P> u ()
		{
			return b - a;
		}
		
		
		/// Returns the second direction vector of the quad plane
		glm::tvec3<T, P> v ()
		{
			return c - a;
		}
		
		
		/// Returns the third direction vector of the quad plane
		glm::tvec3<T, P> w ()
		{
			return d - a;
		}
		
		
		/// Returns the normal of the quad
		glm::tvec3<T, P> normal (bool ccw = true)
		{
			const glm::tvec3<T, P> u = u();
			const glm::tvec3<T, P> v = v();
			
			if (glm::dot(u, v) == 0) return glm::cross(u, w());
			return glm::cross(u, v);
		}
	};
	
	typedef t_quad<float, glm::highp> highp_quad;
	typedef highp_quad quad;
}
#endif
