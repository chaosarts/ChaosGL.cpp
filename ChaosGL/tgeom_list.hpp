//
//  tgeom_list.h
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tgeom_list_h
#define ChaosGL_tgeom_list_h

#include <vector>

#include <glm/glm.hpp>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>

#include "attrib.hpp"
#include "tgeom.hpp"
#include "primitive.hpp"

namespace chaosgl
{
	/**
	 * A Template for geometry (list of vertex positions) inheriting from abstract
	 * struct tgeom, to satisfy geometry structur, and from tattrib_list to store
	 * vertex data in a list.
	 */
	template<typename T, glm::precision P = glm::defaultp>
	struct tgeom_list : public virtual tgeom<T, P>, public virtual tattrib_list<glm::tvec3<T, P>>
	{
	public:
		
		/** Describes its own type */
		typedef tgeom_list<T, P> type;
		
		/** Describes the type of the vertex data */
		typedef glm::tvec3<T, P> vector_type;
		
		/** Describes the inner value type of a vertex data */
		typedef T value_type;
		
		/** Describes the parent data type */
		typedef tgeom<T, P> tgeom;
		
		/** Describes the other parent data type */
		typedef tattrib_list<vector_type> tattrib_list;
		
	private:
		
		/// Provides the min values of x, y and z in this geometry
		vector_type _min;
		
		/// Provides the max values of x, y and z in this geometry
		vector_type _max;
		
	public:
		
		/**
		 * Returns the min values for x, y and z as an vector
		 * @return The min values
		 */
		virtual vector_type getMinValues () const
		{
			return _min;
		}
		
		
		/**
		 * Returns the max values for x, y and z as an vector
		 * @return The max values
		 */
		virtual vector_type getMaxValues () const
		{
			return _max;
		}
		
		
		/**
		 * Returns the index list according to the calls of addValue()
		 * @return A vector of indices refering to the internal list of
		 * 		vertex attribute data
		 */
		virtual std::vector<int> getIndexList () const
		{
			return tattrib_list::getIndexList();
		}
		
		
		/**
		 * Returns the count of vertex attributes according to
		 * given buffer target
		 * @param target The buffer target
		 */
		virtual int count (GLenum target = GL_ARRAY_BUFFER) const
		{
			return tattrib_list::count();
		}
		
		
		/**
		 * Adds a new value to the list
		 */
		virtual void addValue (vector_type value)
		{			
			if (tattrib_list::count() == 0)
			{
				_min.x = value.x;
				_max.x = value.x;
				_min.y = value.y;
				_max.y = value.y;
				_min.z = value.z;
				_max.z = value.z;
			}
			else
			{
				_min.x = std::min(value.x, _min.x);
				_max.x = std::max(value.x, _max.x);
				_min.y = std::min(value.y, _min.y);
				_max.y = std::max(value.y, _max.y);
				_min.z = std::min(value.z, _min.z);
				_max.z = std::max(value.z, _max.z);
			}
			
			tattrib_list::addValue(value);
		}
	};
}

#endif /* tgeom_list_h */
