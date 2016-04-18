//
//  Program.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 18.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGLTest_Program_hpp
#define ChaosGLTest_Program_hpp

#include "Externs.hpp"
#include "Shader.hpp"
#include <gtest/gtest.h>
#include <ChaosGL/Program.hpp>

class Program : public virtual Shader
{
public:
	
	chaosgl::Program* program;
	
	void SetUp ()
	{
		Shader::SetUp();
		vertShader->compile();
		fragShader->compile();
		program = new chaosgl::Program();
		program->bindAttribLocation(CHAOSGL_COLOR, "in_Color");
		program->bindAttribLocation(CHAOSGL_POSITION, "in_Position");
	}
	
	
	virtual ~Program ()
	{
		delete program;
	}
};


TEST_F (Program, Base)
{
	ASSERT_EQ(GL_NO_ERROR, program->attachShader(vertShader));
	ASSERT_EQ(GL_NO_ERROR, program->attachShader(fragShader));
	ASSERT_EQ(GL_NO_ERROR, program->link());
	ASSERT_EQ(GL_NO_ERROR, program->use());
	ASSERT_NE(0, program->getActiveAttributes());
	ASSERT_EQ(CHAOSGL_POSITION, program->getAttribLocation("in_Position"));
	ASSERT_EQ(CHAOSGL_COLOR, program->getAttribLocation("in_Color"));
}

#endif /* Program_h */
