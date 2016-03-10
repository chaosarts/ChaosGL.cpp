//
//  main.cpp
//  ChaosGLTest
//
//  Created by Fu Lam Diep on 08.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include <iostream>
#include <stdarg.h>
#include <vector>
#include <gtest/gtest.h>
#include <OpenGL/OpenGL.h>
#include "ChaosGL.hpp"

using namespace testing;

void error_log (const char* message, ...)
{
	va_list argptr;
	va_start(argptr, message);
	
	char* string = new char();
	vsprintf(string, message, argptr);
	va_end(argptr);
	
	fprintf(stderr, "%s\n", string);
}

TEST_F(ChaosGL, Shader)
{
	ca::gl::Shader* shader = ChaosGL::prepareFragmentShader();
	
	EXPECT_NO_THROW(shader->getId());
	EXPECT_NE(0, shader->getId());
	
	EXPECT_NO_THROW(shader->init());
	EXPECT_NO_THROW(shader->compile());
	EXPECT_EQ(GL_TRUE, shader->getCompileStatus());
	
	delete shader;
}


TEST_F(ChaosGL, Program)
{
	ca::gl::Program* program = ChaosGL::prepareProgram();
	program->attachShaders(ChaosGL::prepareVertexShader());
	program->attachShaders(ChaosGL::prepareFragmentShader());
	
	EXPECT_EQ(GL_NO_ERROR, program->link());
	EXPECT_EQ(GL_TRUE, program->getLinkStatus());
	EXPECT_EQ(GL_TRUE, glIsProgram(program->getId()));
	EXPECT_EQ(GL_TRUE, program->getValidateStatus());
	EXPECT_EQ(GL_NO_ERROR, program->use());
	
	delete program;
}


TEST_F(ChaosGL, Buffer)
{
	ca::gl::Buffer* buffer = new ca::gl::Buffer(GL_ARRAY_BUFFER);
	EXPECT_NE(0, buffer->getId());
	EXPECT_EQ(GL_TRUE, glIsBuffer(buffer->getId()));
	buffer->bind();
	
	vector<int> data = {-1, 0, 0, 0, 1, 0, 1, 0, 0};
	buffer->buffer(sizeof(int) * data.size(), data.data(), GL_STATIC_DRAW);
	
	int* bufferdata = new int();
	glGetBufferSubData(buffer->target, 0, sizeof(int) * data.size(), bufferdata);
	EXPECT_EQ(-1, *(bufferdata));
	
	delete buffer;
	delete bufferdata;
}

int main(int argc, char** argv) {
	InitGoogleTest(&argc, argv);
	if (glfwInit() != GL_TRUE) return 0;
	int result = RUN_ALL_TESTS();
	//glfwTerminate();
	return result;
}
