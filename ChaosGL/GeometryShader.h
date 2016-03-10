/*
 * VertexShader.h
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Geometry_h_
#define _ChaosGL_Geometry_h_

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include "Shader.h"

namespace ca
{
	namespace gl
	{

		class GeometryShader: public Shader
		{
		public:

			/**
			 * Constructor with source and length of source
			 * @param source The source string
			 * @param length
			 */
			GeometryShader(const char* source, int length);


			/**
			 * Constructor with source as file
			 * @param filename
			 */
			GeometryShader(const char* filename);


			/**
			 * Constructor with no source
			 */
			GeometryShader();


			/**
			 * Destructor
			 */
			virtual ~GeometryShader();
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* VERTEXSHADER_H_ */
