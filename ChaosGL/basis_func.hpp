//
//  basis_func.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 15.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_basis_func_hpp
#define ChaosGL_basis_func_hpp

#include "basis.hpp"
#include "triangle.hpp"
#include <glm/glm.hpp>

namespace chaosgl
{
	/**
	 * Normalizes the axis of given basis
	 * @param basis: The basis to normalize
	 * @param The normalized basis
	 */
	template<typename T, glm::precision P = glm::defaultp>
	tbasis3<T, P> normalize(const tbasis3<T, P> &basis)
	{
		return tbasis3<T, P>(glm::normalize(basis.x), glm::normalize(basis.y), glm::normalize(basis.z));
	}
	
	/**
	 * Orthonormalizes the basis
	 * @param basis: The basis to orthonormalize
	 * @param The orthonormalized basis
	 */
	template<typename T, glm::precision P = glm::defaultp>
	tbasis3<T, P> orthonormalize (const tbasis3<T, P> &basis)
	{
		const glm::tvec3<T, P> x = glm::normalize(basis.x);
		const glm::tvec3<T, P> y = glm::normalize(basis.y - glm::dot(x, basis.y) * x);
		const glm::tvec3<T, P> z = glm::normalize(basis.z - glm::dot(y, basis.z) * y - glm::dot(x, basis.z) * x);
		return tbasis3<T, P>(x, y, z);
	}
	
	/**
	 * Creates a tbn basis from given triangles
	 */
	template<typename T, glm::precision P = glm::defaultp>
	tbasis3<T, P> tbn (ttriangle3<T, P> positions, ttriangle2<T, P> texcoords)
	{
		const glm::tmat3x2<T, P> M = _resolve(positions, texcoords);
		const glm::tvec3<T, P> t = glm::tvec3<T, P>(M[0][0], M[1][0], M[2][0]);
		const glm::tvec3<T, P> b = glm::tvec3<T, P>(M[0][1], M[1][1], M[2][1]);
		return Type(t, b, glm::cross(t, b));
	}
	
	
	/**
	 * Creates a tbn basis from given triangles
	 */
	template<typename T, glm::precision P = glm::defaultp>
	tbasis3<T, P> tbn (ttriangle3<T, P> positions, ttriangle2<T, P> texcoords, glm::tvec3<T, P> normal)
	{
		const glm::tmat3x2<T, P> M = _resolve(positions, texcoords);
		const glm::tvec3<T, P> t = glm::tvec3<T, P>(M[0][0], M[1][0], M[2][0]);
		const glm::tvec3<T, P> b = glm::tvec3<T, P>(M[0][1], M[1][1], M[2][1]);
		return tbasis3<T, P>(t, b, normal);
	}
	
	
	/**
	 * Returns the transition matrix from one base to another
	 * @param from: The basis to transit from
	 * @param to: The basis to transit to
	 * @return The transition matrix
	 */
	template<typename T, glm::precision P = glm::defaultp>
	glm::tmat3x3<T, P> transitionMatrix (const tbasis3<T, P> &from, const tbasis3<T, P> &to)
	{
		const glm::tmat3x3<T, P> from_mat(from.x, from.y, from.z);
		const glm::tmat3x3<T, P> to_mat(to.x, to.y, to.z);
		return glm::inverse(to_mat) * from_mat;
	}
}

#endif /* basis_func_h */
