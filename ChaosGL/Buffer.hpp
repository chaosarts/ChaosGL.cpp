/*
 * Buffer.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Buffer_hpp
#define ChaosGL_Buffer_hpp

#include "ChaosGL.hpp"
#include <stdlib.h>

namespace chaosgl
{
	class Buffer
	{
	private:
		
		/** Provides the buffer id */
		GLuint* const _id;
		
	public:
		
		/** Provides the target of the buffer */
		const GLenum target;
		
		
		/**
		 * Creates a new buffer object
		 * @param target
		 */
		Buffer(GLenum target);
		
		/**
		 * Destructor
		 */
		virtual ~Buffer();
		
		/**
		 * Returns the id of the buffer
		 */
		GLuint getId ();
		
		
		/**
		 * Binds the buffer
		 */
		void bind ();
		
		
		/**
		 * Unbinds the buffer
		 */
		void unbind ();
		
		
		/**
		 * Buffers data
		 */
		void buffer (GLsizeiptr size, const GLvoid* data, GLenum usage);
		
		
		/**
		 * Determines whether the object is a buffer or not
		 */
		GLboolean isBuffer ();
	};
}

#endif /* BUFFER_H_ */
