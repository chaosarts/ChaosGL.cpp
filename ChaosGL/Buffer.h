/*
 * Buffer.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Buffer_h_
#define _ChaosGL_Buffer_h_

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include <stdlib.h>
#include <ChaosCore/core.h>

namespace ca
{
	namespace gl
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

} /* namespace creategl */

#endif /* BUFFER_H_ */
