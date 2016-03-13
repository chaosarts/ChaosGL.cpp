/*
 * VertexShader.h
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Fragment_h_
#define ChaosGL_Fragment_h_

#include "Shader.hpp"
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
	{

		class FragmentShader: public Shader
		{
		public:

			/**
			 * Constructor with source and length of source
			 * @param source The source string
			 * @param length
			 */
			FragmentShader(const char* source, int length);


			/**
			 * Constructor with source as file
			 * @param filename
			 */
			FragmentShader(const char* filename);


			/**
			 * Constructor with no source
			 */
			FragmentShader();


			/**
			 * Destructor
			 */
			virtual ~FragmentShader();
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* VERTEXSHADER_H_ */
