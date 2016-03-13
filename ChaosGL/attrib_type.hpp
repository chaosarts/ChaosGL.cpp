//
//  attrib.h
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_attrib_base_hpp_
#define ChaosGL_attrib_base_hpp_

#include <vector>
#include <map>
#include <OpenGL/OpenGL.h>
#include <glm/glm.hpp>
#include "attrib_func.hpp"

using namespace glm;
using namespace std;

namespace ca
{
	namespace gl
	{
		
		template<typename T>
		struct tattrib
		{
		public:
			
			typedef tattrib<T> type;
			
			/// Provides the data type
			typedef T value_type;
			
			
			/// Destroys the attribute
			virtual ~tattrib () {};
			
			
			/// 
			virtual T getValue (int index) = 0;
			
			
			/// Returns the count of attribute values
			/// A negative value indicates, that the struct serves
			/// infinite values.
			virtual int count () const = 0;
			
			
			/// Returns the size of the attribute per vertex (1, 2, 3 or 4)
			int size () const
			{
				return element_count(T());
			}
			
			
			/// Provides the size of the attribute per vertex
			long byteSizePerVertex () const
			{
				return sizeof(T);
			}
			
			
			/// Returns the total byte size of the attribute
			long totalByteSize () const
			{
				return byteSizePerVertex() * count();
			}
		};
		
		
		/// A conventional attribute struct that provides a list of values.
		/// Internaly it provides a list of unique values by providing an
		/// additional indexlist, which indicates the actual value sequence
		/// of the attribute. This index list can also be used for glDrawElements
		/// when buffering the values as it is actually stored in this struct.
		template<typename T>
		struct tattrib_list : public tattrib<T>
		{
		protected:
			
			/// Provides a list of value of the attribtute with no duplicates
			/// A new element is added to this list, if the value has not
			/// been added before. The actual value sequence is indicated by the
			/// index list
			vector<T> _values;
			
			/// Provides the a list of indices, which refers to the indices of the value
			/// list. The order of these indices represents the order, in which the
			/// values has actually been added.
			vector<int> _indexlist;
			
		public:
			
			/// Describes its own type
			typedef tattrib_list<T> type;
			
			/// Describes the type of the values
			typedef T value_type;
			
			
			/// Destroy the attrib list object
			virtual ~tattrib_list () {}
			
			
			/// Depending on the draw mode it returns the count of
			/// unique values (ELEMENTS) or the count of indexlist (ARRAYS)
			virtual int count () const
			{
				return (int) _values.size();
			}
			
			
			/// Sames as operator[index]
			virtual T getValue (int index)
			{
				if (index < 0 || index >= _values.size())
					throw "<tattrib_list> Invalid index";
				
				return *(_values.begin() + index);
			}
			
			
			/// Returns the index of the value in this attrib list
			int indexOf (T value)
			{
				int index = 0;
				while (index < (int) _values.size())
				{
					if (_values[index] == value) return index;
					index++;
				}
				
				return -1;
			}
			
			
			/// Adds a new value to the attribute. If the same value has been added before,
			/// indexlist only will be updated
			void add (T value)
			{
				/// Generate key from value and check if the value has been added before
				int index = indexOf(value);

				if (index < 0)
				{
					index = (int) _values.size();
					_values.push_back(value);
				}
				
				addIndex (index);
			}
			
			
			/// Updates value sequence
			void addIndex (int index)
			{
				if (index < 0 || index >= _values.size()) return;
				_indexlist.push_back(index);
			}
			
			
			/// Returns the index list for glDrawElements
			vector<int> getIndexlist ()
			{
				return _indexlist;
			}
		};
		
		
		/// This struct provides only a single value but serves
		/// it to each desired index.
		template<typename T>
		struct tattrib_const : public tattrib<T>
		{
		public:
			/// Provides the single value, which will be passed for any index
			T value;
			
			
			/// Destructor
			virtual ~tattrib_const () {}
			
			
			/// Array access operator. Always returns the provides value
			T operator[] (int index)
			{
				return value;
			}
			
			
			/// Since it can serve values for any value of index
			/// this returns -1
			int count ()
			{
				// Indicating infinite value serving
				return -1;
			}
		};
		
		
//		template<typename T, glm::precision P = glm::defaultp>
//		struct tattrib_gen : public tattrib<T, P>
//		{
//		public:
//		};
	}
}
#endif /* attrib_h */
