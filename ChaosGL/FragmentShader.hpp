/*
 * VertexShader.h
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Fragment_hpp
#define ChaosGL_Fragment_hpp

#include "Shader.hpp"
#include "ChaosGL.hpp"

namespace chaosgl
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
} /* namespace ca */

#endif /* VERTEXSHADER_H_ */
