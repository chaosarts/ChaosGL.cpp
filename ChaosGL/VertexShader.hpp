/*
 * VertexShader.h
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_VertexShader_h_
#define _ChaosGL_VertexShader_h_

#include "Shader.hpp"
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
	{

		class VertexShader: public Shader
		{
		public:

			/**
			 * Constructor with source and length of source
			 * @param source The source string
			 * @param length
			 */
			VertexShader(const char* source, int length);


			/**
			 * Constructor with source as file
			 * @param filename
			 */
			VertexShader(const char* filename);


			/**
			 * Constructor with no source
			 */
			VertexShader();


			/**
			 * Destructor
			 */
			virtual ~VertexShader();
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* VERTEXSHADER_H_ */
