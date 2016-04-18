/*
 * Program.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "Program.hpp"
#include "Exception.hpp"
#include "Shader.hpp"
#include <ChaosCore/ChaosCore.hpp>
#include <map>

namespace chaosgl
{
	std::map<GLint, Program*> _idProgramMap;
	
	
	GLint Program::current()
	{
		GLint param;
		glGetIntegerv(GL_CURRENT_PROGRAM, &param);
		return param;
	}
	
	
	Program* Program::get (GLuint index)
	{
		std::map<GLint, Program*>::iterator it = _idProgramMap.find(index);
		return it == _idProgramMap.end() ? nullptr : it->second;
	}
	
	
	Program::Program()
	{
		_idProgramMap[getId()] = this;
	}
	
	
	Program::~Program()
	{
		glDeleteProgram(getId());
	}
	
	
	GLuint Program::getId()
	{
		if (_id == 0)
		{
			_id = glCreateProgram();
			if (_id == 0) chaos::warn("<Program> Unable to create: Is there an OpenGL context initialized?");
		}
		
		return _id;
	}
	
	
	GLint Program::link()
	{
		if (getLinkStatus() == GL_TRUE)
			return GL_NO_ERROR;
		
		_attribLocationCache.clear();
		_uniformLocationCache.clear();
		
		glLinkProgram(getId());
		
		GLint error = glGetError();
		chaos::info("<Program> Result of 'link': %i", error);
		
		return error;
	}
	
	
	GLint Program::use()
	{
		if (getLinkStatus() != GL_TRUE)
			chaos::warn("Unable to use Program: Link status is false. Did you call link before?");
		
		glUseProgram(getId());
		
		GLint error = glGetError();
		chaos::info("<Program> Result of 'use': %i", error);
		
		return error;
	}
	
	
	GLenum Program::attachShader (GLuint shader)
	{
		glAttachShader(getId(), shader);
		const GLenum error = glGetError();
		chaos::info("<Program> Error result of attachShader: %i", error);
		return error;
	}
	
	
	GLenum Program::attachShader (chaosgl::Shader *shader)
	{
		shader->compile();
		return attachShader (shader->getId());
	}
	
	
	void Program::detachShader (GLuint shader)
	{
		glDetachShader(getId(), shader);
	}
	
	
	void Program::detachShader (chaosgl::Shader *shader)
	{
		detachShader(shader->getId());
	}
	
	
	void Program::bindAttribLocation(GLuint index, const char* name)
	{
		glBindAttribLocation(getId(), index, name);
		_attribLocationCache[name] = index;
	}
	
	
	GLint Program::getAttribLocation(const char *name)
	{
		std::map<const char*, GLuint>::iterator it = _attribLocationCache.find(name);
		if (it != _attribLocationCache.end()) return it->second;
		
		GLint index = glGetAttribLocation(getId(), name);
		if (index < 0) chaos::info("<Program> Attribute %s not found.", name);
		else _attribLocationCache[name] = GLuint(index);
		
		return index;
	}
	
	
	GLint Program::getUniformLocation(const char *name)
	{
		std::map<const char*, GLuint>::iterator it = _uniformLocationCache.find(name);
		if (it != _uniformLocationCache.end()) return it->second;
		
		GLint index = glGetUniformLocation(getId(), name);
		if (index < 0) chaos::info("<Program> Uniform %s not found", name);
		else _uniformLocationCache[name] = GLuint(index);
		
		return index;
	}
	
	
	const char* Program::getInfoLog()
	{
		GLint length = getInfoLogLength();
		GLchar* infoLog = new GLchar[length];
		glGetProgramInfoLog(getId(), GLsizei(length), &length, infoLog);
		return infoLog;
	}
	
	
	GLboolean Program::isProgram()
	{
		return glIsProgram(getId());
	}
	
	
	GLint Program::getParam(GLenum pname)
	{
		GLint param = 0;
		glGetProgramiv(getId(), pname, &param);
		return param;
	}
	
	
	GLint Program::getLinkStatus()
	{
		return getParam(GL_LINK_STATUS);
	}
	
	
	GLint Program::getDeleteStatus()
	{
		return getParam(GL_DELETE_STATUS);
	}
	
	
	GLint Program::getValidateStatus()
	{
		return getParam(GL_VALIDATE_STATUS);
	}
	
	
	GLint Program::getAttachedShaders()
	{
		return getParam(GL_ATTACHED_SHADERS);
	}
	
	
	GLint Program::getInfoLogLength()
	{
		return getParam(GL_INFO_LOG_LENGTH);
	}
	
	
	GLint Program::getActiveAttributes()
	{
		return getParam(GL_ACTIVE_ATTRIBUTES);
	}
	
	
	GLint Program::getActiveAttributeMaxLength()
	{
		return getParam(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
	}
	
	
	GLint Program::getActiveUniforms()
	{
		return getParam(GL_ACTIVE_UNIFORMS);
	}
	
	
	GLint Program::getActiveUniformMaxLength()
	{
		return getParam(GL_ACTIVE_UNIFORM_MAX_LENGTH);
	}
}



