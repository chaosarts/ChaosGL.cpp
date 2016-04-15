//
//  tgeom.h
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tgeom_hpp
#define ChaosGL_tgeom_hpp

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
		typedef tgeom<T, P> Type;
		
		/** Describes the vector type */
		typedef glm::tvec3<T, P> vec3;
		
		/** Describes the triangle type */
		typedef ttriangle3<T, P> triangle3;
		
		/** Describes the value type of the vector */
		typedef T ValueType;
		
		
		/**
		 * Returns the min values for x, y and z as an vector
		 * @return The min values
		 */
		virtual vec3 getMinValues () const  = 0;
		
		
		/**
		 * Returns the max values for x, y and z as an vector
		 * @return The max values
		 */
		virtual vec3 getMaxValues () const  = 0;
		
		
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
		triangle3 getTriangle (int index) const
		{
			const int count = getTriangleCount();
			const int start_index = index * 3;
			if (start_index < 0 || start_index + 2 >= count) throw "<geom> Could not get triangle for index";
			
			vec3 a = this->getValue(start_index, GL_ARRAY_BUFFER);
			vec3 b = this->getValue(start_index + 1, GL_ARRAY_BUFFER);
			vec3 c = this->getValue(start_index + 2, GL_ARRAY_BUFFER);
			
			return triangle3(a, b ,c);
		}
		
		
		std::vector<triangle3> getTriangles (vec3 value) const
		{
			const int vIndex = this->indexOf(value);
			std::vector<int> indexlist = this->getIndexList();
			std::vector<int>::iterator it = indexlist.begin();
			std::vector<triangle3> triangles;
			
			int iIndex = 0;
			while (it != indexlist.end())
			{
				if (*it == vIndex)
				{
					const std::vector<int>::iterator startIt = it - (iIndex % 3);
					const vec3 a = this->getValue(*startIt, GL_ELEMENT_ARRAY_BUFFER);
					const vec3 b = this->getValue(*(startIt + 1), GL_ELEMENT_ARRAY_BUFFER);
					const vec3 c = this->getValue(*(startIt + 2), GL_ELEMENT_ARRAY_BUFFER);
					triangles.push_back(triangle3(a, b, c));
				}
				it++;
				iIndex++;
				
			}
			return triangles;
		}
	};
}

#endif /* tgeom_h */
