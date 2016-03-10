/*
 * Program.cpp
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#include "Program.h"

namespace ca
{
	namespace gl
	{
		Program::Program() {}

		
		Program::~Program()
		{
			glDeleteProgram(getId());
		}
		
		
		GLint Program::link()
		{
			if (getLinkStatus() == GL_TRUE)
				return GL_NO_ERROR;
			
			_attribLocationCache.clear();
			_uniformLocationCache.clear();
			
			GLuint id = getId();
			vector<GLuint>::iterator it = _shaders.begin();
			while (it != _shaders.end())
				glAttachShader(id, *it++);
			
			glLinkProgram(id);
			
			GLint error = glGetError();
			ca::core::info("<Program> Result of 'link': %i", error);
			
			return error;
		}
		
		
		GLint Program::use()
		{
			if (getLinkStatus() != GL_TRUE)
				ca::core::warn("Unable to use Program: Link status is false. Did you call link before?");
			
			glUseProgram(getId());
			
			GLint error = glGetError();
			ca::core::info("<Program> Result of 'use': %i", error);

			return error;
		}
		
		
		void Program::attachShaders(GLuint shader)
		{
			_shaders.push_back(shader);
		}
		
		
		void Program::attachShaders(ca::gl::Shader *shader)
		{
			try {
				shader->compile();
				attachShaders(shader->getId());
			}
			catch (ca::gl::Exception* e) {
				ca::core::warn("<Program> Shader not attached to program: %s", e->message);
			}
		}
		
		
		void Program::bindAttribLocation(GLuint index, const char* name)
		{
			glBindAttribLocation(getId(), index, name);
		}
		
		
		GLuint Program::getAttribLocation(const char *name)
		{
			map<const char*, GLuint>::iterator it = _attribLocationCache.find(name);
			if (it != _attribLocationCache.end()) return it->second;
			
			GLint index = glGetAttribLocation(getId(), name);
			if (index < 0) ca::core::info("<Program> Attribute %s not found.", name);
			else _attribLocationCache[name] = GLuint(index);
			return index;
		}
		
		
		
		GLuint Program::getUniformLocation(const char *name)
		{
			map<const char*, GLuint>::iterator it = _attribLocationCache.find(name);
			if (it != _attribLocationCache.end()) return it->second;
			
			GLint index = glGetUniformLocation(getId(), name);
			if (index < 0) ca::core::info("<Program> Uniform %s not found", name);
			else _uniformLocationCache[name] = GLuint(index);
			
			return index;
		}
		
		
		GLuint Program::getId()
		{
			if (_id == 0)
			{
				_id = glCreateProgram();
				if (_id == 0) ca::core::warn("<Program> Unable to create: Is there an OpenGL context initialized?");
			}
			
			return _id;
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



} /* namespace creategl */
