//
//  Bufferable.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 19.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_Bufferable_hpp
#define ChaosGL_Bufferable_hpp

#include "ChaosGL.hpp"

namespace chaosgl
{
	/**
	 * Bufferable is a struct, which holds data for a vertex attribute.
	 * The opaque data of the vertex attribute of a certain index is 
	 * accessed over getData or []-operator.
	 */
	struct Bufferable
	{
	public:
		/** Provides the size in bytes of the bufferable per vertex */
		const GLsizeiptr byteSize;
		
		/**
		 * Creates a new bufferable object
		 */
		Bufferable (GLsizeiptr byteSize);
		
		/**
		 * Returns a void pointer to the data of the vertex attribute 
		 * at given index
		 * @param index
		 * @param traget
		 * @return The data pointer
		 */
		virtual void* getData (int index, GLenum target) const = 0;
		
		
		/**
		 * Desytroys the buffer able data
		 */
		virtual ~Bufferable ();
	};
}

#endif /* Bufferable_h */
