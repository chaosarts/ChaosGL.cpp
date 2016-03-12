/*
 * Buffer.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "Buffer.hpp"

namespace ca
{
	namespace gl
	{
		Buffer::Buffer(GLenum target) : _id((GLuint*) malloc(sizeof(GLuint))), target(target)
		{
			*_id = 0;
		}


		Buffer::~Buffer()
		{
			glDeleteBuffers(1, _id);
		}
		
		
		GLuint Buffer::getId ()
		{
			if (*_id == 0)
			{
				glGenBuffers(1, _id);
				if (*_id == 0) ca::core::warn("<Buffer> Unable to create: Do you have an active OpenGL context?");
			}
			
			return *_id;
		}


		void Buffer::bind()
		{
			glBindBuffer(target, getId());
		}


		void Buffer::unbind()
		{
			glBindBuffer(target, 0);
		}


		void Buffer::buffer(GLsizeiptr size, const GLvoid* data, GLenum usage)
		{
			glBufferData(target, size, data, usage);
		}
		
		
		GLboolean Buffer::isBuffer()
		{
			return glIsBuffer(getId());
		}
	}

} /* namespace creategl */
