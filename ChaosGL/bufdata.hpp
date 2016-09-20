//
//  bufdata.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 19.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_bufdata_hpp
#define ChaosGL_bufdata_hpp

#include "ChaosGL.hpp"

namespace chaosgl
{
	struct bufdata
	{
	public:
		
		/** Provides the pointer, that points to the beginning of the data*/
		GLvoid* const begin;
		
		/** Provides the size of the buffer data in bytes */
		const GLsizeiptr size;
		
		/**
		 * Creates a new buffer data object
		 * @param size: The size of the buffer data to allocate in bytes
		 */
		bufdata (GLsizeiptr size);
		
		
		/**
		 * Appends data to this buffer data
		 */
		void push (void* data, GLsizeiptr size);
		
		
		/**
		 * Destroys the buffer data object and the data
		 */
		virtual ~bufdata ();
		
	private:
		
		/** Provides a pointer that points to an address within the data */
		GLvoid* _current;
	};
}

#endif /* bufdata_hpp */
