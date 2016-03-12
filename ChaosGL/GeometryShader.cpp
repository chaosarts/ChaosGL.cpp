/*
 * VertexShader.cpp
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#include "GeometryShader.hpp"

namespace ca
{
	namespace gl
	{
		GeometryShader::GeometryShader(const char* source, int length) : Shader(GL_GEOMETRY_SHADER, source, length) {}

		GeometryShader::GeometryShader(const char* filename) : Shader(GL_GEOMETRY_SHADER, filename) {}

		GeometryShader::GeometryShader() : Shader(GL_GEOMETRY_SHADER) {}

		GeometryShader::~GeometryShader() {}

	} /* namespace gl */
} /* namespace ca */
