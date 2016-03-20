//
//  tgeom.h
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tgeom_h
#define ChaosGL_tgeom_h

#include <glm/glm.hpp>
#include "attrib.hpp"
#include "primitive.hpp"

namespace chaosgl
{
	template<typename T, glm::precision P = glm::defaultp>
	struct tgeom : tattrib_countable<glm::tvec3<T, P>>
	{
	public:
		
		/** Describes its own type */
		typedef tgeom<T, P> type;
		
		
		/** Describes the vector type */
		typedef glm::tvec3<T, P> vertex_type;
		
		
		/** Describes the value type of the vector */
		typedef T value_type;
		
		
		/**
		 * Returns the min values for x, y and z as an vector
		 * @return The min values
		 */
		virtual vertex_type getMinValues () const  = 0;
		
		
		/**
		 * Returns the max values for x, y and z as an vector
		 * @return The max values
		 */
		virtual vertex_type getMaxValues () const  = 0;
		
		
		/** 
		 * Returns the count of primitives of given size
		 * @return The count of primitives
		 */
		int getPrimitiveCount (int primitve_size) const
		{
			return (int) this->count(GL_ARRAY_BUFFER) / primitve_size;
		}
		
		
		/**
		 * Shortcut for getPrimitveCount(3)
		 * @return The count of triangle primitves in this geometry
		 */
		int getTriangleCount () const
		{
			return getPrimitiveCount(3);
		}
		
		
		/**
		 * Returns a list of triangles
		 */
		ttriangle<T, P> getTriangle (int index) const
		{
			const int count = getTriangleCount();
			const int start_index = index * 3;
			if (start_index < 0 || start_index + 2 >= count) throw "<geom> Could not get triangle for index";
			
			vertex_type a = this->getValue(start_index, GL_ARRAY_BUFFER);
			vertex_type b = this->getValue(start_index + 1, GL_ARRAY_BUFFER);
			vertex_type c = this->getValue(start_index + 2, GL_ARRAY_BUFFER);
			
			return ttriangle<T, P>(a, b ,c);
		}
		
		
		/**
		 * Shortcut for getPrimitiveCount(4)
		 * @return The count of quads
		 */
		virtual int getQuadCount () const
		{
			return getPrimitiveCount(4);
		}
		
		
		/**
		 * Returns a list of quad objects
		 * @return a list of quads
		 */
		virtual tquad<T, P> getQuad (int index) const
		{
			const int count = getQuadCount();
			const int start_index = index * 4;
			if (start_index < 0 || start_index + 2 >= count) throw "<geom> Could not get triangle for index";
			
			vertex_type a = this->getValue(start_index, GL_ARRAY_BUFFER);
			vertex_type b = this->getValue(start_index + 1, GL_ARRAY_BUFFER);
			vertex_type c = this->getValue(start_index + 2, GL_ARRAY_BUFFER);
			vertex_type d = this->getValue(start_index + 3, GL_ARRAY_BUFFER);
			
			return tquad<T, P>(a, b ,c, d);
		}

	};
}

#endif /* tgeom_h */
