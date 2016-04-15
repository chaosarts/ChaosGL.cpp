/*
 * Shader.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "Shader.hpp"
#include <ChaosCore/ChaosCore.hpp>
#include <sys/stat.h>

namespace chaosgl
{
	Shader::Shader(GLenum type, const char* source, int length) : type(type)
	{
		addSource(source, length);
	}
	
	
	Shader::Shader(GLenum type, const char* filename) : type(type)
	{
		addSource(filename);
	}
	
	
	Shader::Shader(GLenum type) : type(type)
	{
		
	}
	
	
	Shader::~Shader()
	{
		glDeleteShader(_id);
	}
	
	
	GLint Shader::init ()
	{
		if (_initialized) return GL_NO_ERROR;
		
		glShaderSource(getId(), GLsizei(_sources.size()), _sources.data(), nullptr);
		
		GLenum error = glGetError();
		chaos::info("<Shader> Result of 'init': %i", error);
		
		_initialized = GL_NO_ERROR == error;
		return error;
	}
	
	
	GLint Shader::compile()
	{
		if (_compiled) return GL_NO_ERROR;
		
		GLenum error = init();
		if (GL_NO_ERROR != error) return error;
		
		glCompileShader(getId());
		
		error = glGetError();
		chaos::info("<Shader> Result of 'compile': %i", error);
		
		_compiled = GL_NO_ERROR == error;
		return error;
	}
	
	
	GLuint Shader::getId()
	{
		if (_id == 0)
		{
			_id = glCreateShader(type);
			if (_id == 0) chaos::warn("<Shader> Invalid type.");
		}
		return _id;
	}
	
	
	GLint Shader::getParam(GLenum pname)
	{
		GLint value;
		glGetShaderiv(getId(), pname, &value);
		return value;
	}
	
	
	GLint Shader::getCompileStatus()
	{
		return getParam(GL_COMPILE_STATUS);
	}
	
	
	GLint Shader::getDeleteStatus()
	{
		return getParam(GL_DELETE_STATUS);
	}
	
	
	GLint Shader::getInfoLogLength()
	{
		return getParam(GL_INFO_LOG_LENGTH);
	}
	
	
	GLint Shader::getSourceLength()
	{
		return getParam(GL_SHADER_SOURCE_LENGTH);
	}
	
	
	const char* Shader::getInfoLog()
	{
		GLsizei length = getInfoLogLength();
		GLchar* infoLog = new GLchar[length];
		glGetShaderInfoLog(getId(), GLsizei(getInfoLogLength()), &length, infoLog);
		return infoLog;
	}
	
	
	void Shader::addSource(const char* source, int length)
	{
		int size = length;
		if (source[length - 1] != 0) size++;
		
		char* src;
		src = new char[size];
		strcpy(src, source);
		src[size] = 0;
		
		_sources.push_back(src);
		_compiled = false;
		_initialized = false;
	}
	
	
	void Shader::addSource(const char* filename)
	{
		struct stat buffer;
		if (stat(filename, &buffer) != 0)
		{
			chaos::warn("<Shader> File %s not found.", filename);
			return;
		}
		
		FILE* handler = fopen(filename, "r");
		fseek(handler, 0, SEEK_END);
		long length = ftell(handler);
		if (length == -1)
		{
			fclose(handler);
			chaos::warn("<Shader> File %s does not support pointer position.", filename);
			return;
		}
		
		fseek(handler, 0, SEEK_SET);
		char* source = new char[length];
		fread(source, 1, length, handler);
		fclose(handler);
		
		addSource(source, (int) length);
	}
}