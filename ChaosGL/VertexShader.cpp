/*
 * VertexShader.cpp
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#include "VertexShader.h"

namespace ca
{
	namespace gl
	{
		VertexShader::VertexShader(const char* source, int length) : Shader(GL_VERTEX_SHADER, source, length) {}

		VertexShader::VertexShader(const char* filename) : Shader(GL_VERTEX_SHADER, filename) {}

		VertexShader::VertexShader() : Shader(GL_VERTEX_SHADER) {}

		VertexShader::~VertexShader() {}

	} /* namespace gl */
} /* namespace ca */
