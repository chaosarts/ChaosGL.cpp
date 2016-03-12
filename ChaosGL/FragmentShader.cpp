/*
 * VertexShader.cpp
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#include "FragmentShader.hpp"

namespace ca
{
	namespace gl
	{
		FragmentShader::FragmentShader(const char* source, int length) : Shader(GL_FRAGMENT_SHADER, source, length) {}

		FragmentShader::FragmentShader(const char* filename) : Shader(GL_FRAGMENT_SHADER, filename) {}

		FragmentShader::FragmentShader() : Shader(GL_FRAGMENT_SHADER) {}

		FragmentShader::~FragmentShader() {}

	} /* namespace gl */
} /* namespace ca */
