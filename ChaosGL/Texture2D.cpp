//
//  Texture2D.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 21.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Texture2D.hpp"
#include <ChaosCore/ChaosCore.hpp>

namespace chaosgl
{
	
	Texture2D::Texture2D () : Texture (GL_TEXTURE_2D) {}
	
	
	Texture2D::~Texture2D () {}
	
	
	void Texture2D::setData(const GLvoid *data)
	{
		glTexImage2D(target, level, internalFormat, width, height, 0, format, type, data);
	}
	
	void Texture2D::setWrapT(GLint value)
	{
		setParam(GL_TEXTURE_WRAP_T, value);
	}
	
	
	GLint Texture2D::getWrapT()
	{
		GLint param;
		getParami(GL_TEXTURE_WRAP_T, &param);
		return param;
	}
}