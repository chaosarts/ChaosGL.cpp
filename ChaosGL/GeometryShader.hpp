/*
 * VertexShader.h
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Geometry_hpp
#define ChaosGL_Geometry_hpp

#include "ChaosGL.hpp"
#include "Shader.hpp"

namespace chaosgl
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
} /* namespace ca */

#endif /* VERTEXSHADER_H_ */
