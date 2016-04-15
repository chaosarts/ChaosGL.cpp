//
//  tattrib_list.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_tattrib_list_hpp
#define ChaosGL_tattrib_list_hpp

#include <vector>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include "tattrib.hpp"

namespace chaosgl
{
	/**
	 * Vertex attribute struct to store values as list. The count of
	 * added vertex data to this structure is commonly not the same
	 * count of the stored values. Vertex data with the same value as
	 * a previously stored data, will be stored only once. Instead a
	 * list of indices is provided, of which each entry contains the index
	 * to the according data in the values list.
	 */
	template<typename T>
	struct tattrib_list : public virtual tattrib_countable<T>
	{
	protected:
		
		/** Provides a list of unique vertex values */
		std::vector<T> _values;
		
		/**
		 * Provides the a list of indices, which refers to the indices of the value
		 * list. The order of these indices represents the order, in which the
		 * values has actually been added.
		 */
		std::vector<int> _indexlist;
		
	public:
		
		/** Describes its own type */
		typedef tattrib_list<T> Type;
		
		/** Describes the type of the values */
		typedef T VertexType;
		
		
		/** Destroy the attrib list object */
		virtual ~tattrib_list () {}
		
		
		/**
		 * Returns the count of values depending on the buffer target
		 */
		virtual int count (GLenum target = GL_ARRAY_BUFFER) const
		{
			switch (target)
			{
				case GL_ARRAY_BUFFER:
					return (int) _indexlist.size();
				case GL_ELEMENT_ARRAY_BUFFER:
					return (int) _values.size();
				default:
					throw "<tattrib_list> Invalid target for count()";
			}
		}
		
		
		/**
		 * Returns the index of the vertex from the vertex list.
		 * @param vertex
		 * @return The index of the vertex
		 */
		int indexOf (VertexType value) const
		{
			int index = 0;
			while (index < (int) _values.size())
			{
				if (_values[index] == value) return index;
				index++;
			}
			
			return -1;
		}
		
		
		/** 
		 * Sames as operator[index] 
		 */
		virtual VertexType getValue (int index, GLenum target = GL_ARRAY_BUFFER) const
		{
			int i = target == GL_ARRAY_BUFFER ? _indexlist[index] : index;
			return *(_values.begin() + i);
		}
		
		
		/**
		 * Adds a new value to the attribute. If the same value has been added before,
		 * indexlist only will be updated
		 */
		virtual void addValue (VertexType value)
		{
			/// Generate key from value and check if the value has been added before
			int index = indexOf(value);
			
			if (index < 0)
			{
				index = (int) _values.size();
				_values.push_back(value);
			}
			_indexlist.push_back(index);
		}
		
		
		/**
		 * Returns the index list for glDrawElements
		 * @return The index list
		 */
		virtual std::vector<int> getIndexList () const
		{
			return _indexlist;
		}
	};
}
#endif
