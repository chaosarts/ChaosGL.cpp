//
//  Texture.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 20.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Texture.hpp"
#include <ChaosCore/ChaosCore.hpp>

namespace chaosgl
{
	Texture::Texture (GLenum target) : target(target) {}
	
	
	Texture::~Texture() {}
	
	
	GLuint Texture::getId ()
	{
		if (_id == 0)
		{
			glGenTextures(1, &_id);
			if (0 == _id) chaos::warn("Could not generate texture. Is there a OpenGL constext?");
		}
		
		return _id;
	}
	
	
	void Texture::bind ()
	{
		glBindTexture(target, getId());
	}
	
	
	void Texture::setParam(GLenum pname, GLfloat value)
	{
		glTexParameterf(target, pname, value);
	}
	
	
	void Texture::setParam(GLenum pname, GLfloat* value)
	{
		glTexParameterfv(target, pname, value);
	}
	
	
	void Texture::getParamf(GLenum pname, GLfloat *value)
	{
		glGetTexParameterfv(target, pname, value);
	}
	
	
	void Texture::setParam(GLenum pname, GLint value)
	{
		glTexParameteri(target, pname, value);
	}
	
	
	void Texture::setParam(GLenum pname, GLint* value)
	{
		glTexParameteriv(target, pname, value);
	}
	
	
	void Texture::getParami(GLenum pname, GLint *value)
	{
		glGetTexParameteriv(target, pname, value);
	}
	
	
	void Texture::setMinFilter(GLint value)
	{
		setParam(GL_TEXTURE_MIN_FILTER, value);
	}
	
	
	GLint Texture::getMinFilter()
	{
		GLint param;
		getParami(GL_TEXTURE_MIN_FILTER, &param);
		return param;
	}
	
	
	void Texture::setMagFilter(GLint value)
	{
		setParam(GL_TEXTURE_MAG_FILTER, value);
	}
	
	
	GLint Texture::getMagFilter()
	{
		GLint param;
		getParami(GL_TEXTURE_MAG_FILTER, &param);
		return param;
	}
	
	
	void Texture::setMinLod (GLint value)
	{
		setParam(GL_TEXTURE_MIN_LOD, value);
	}
	
	
	GLint Texture::getMinLod()
	{
		GLint param;
		getParami(GL_TEXTURE_MIN_LOD, &param);
		return param;
	}
	
	
	void Texture::setMaxLod (GLint value)
	{
		setParam(GL_TEXTURE_MAX_LOD, value);
	}
	
	
	GLint Texture::getMaxLod()
	{
		GLint param;
		getParami(GL_TEXTURE_MAX_LOD, &param);
		return param;
	}
	
	
	void Texture::setBaseLevel (GLint value)
	{
		setParam(GL_TEXTURE_BASE_LEVEL, value);
	}
	
	
	GLint Texture::getBaseLevel()
	{
		GLint param;
		getParami(GL_TEXTURE_BASE_LEVEL, &param);
		return param;
	}
	
	
	void Texture::setMaxLevel (GLint value)
	{
		setParam(GL_TEXTURE_MAX_LEVEL, value);
	}
	
	
	GLint Texture::getMaxLevel()
	{
		GLint param;
		getParami(GL_TEXTURE_MAX_LEVEL, &param);
		return param;
	}
	
	
	void Texture::setWrapS (GLint value)
	{
		setParam(GL_TEXTURE_WRAP_S, value);
	}
	
	
	GLint Texture::getWrapS()
	{
		GLint param;
		getParami(GL_TEXTURE_WRAP_S, &param);
		return param;
	}
	
	
	void Texture::setBorderColor(GLfloat *color)
	{
		setParam(GL_TEXTURE_BORDER_COLOR, color);
	}
	
	
	void Texture::setBorderColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
	{
		GLfloat color[4] = {red, green, blue, alpha};
		setBorderColor(color);
	}
	
	
	GLfloat* Texture::getBorderColor()
	{
		GLfloat* param;
		getParamf(GL_TEXTURE_BORDER_COLOR, param);
		return param;
	}
	
#ifdef GL_TEXTURE_PRIORITY
	void Texture::setPriority(GLfloat value)
	{
		setParam(GL_TEXTURE_PRIORITY, value);
	}
#endif
	
	
	GLboolean Texture::isTexture ()
	{
		return glIsTexture(getId());
	}
}