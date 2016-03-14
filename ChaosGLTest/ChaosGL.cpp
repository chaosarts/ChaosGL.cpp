//
//  Base.cpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 08.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "ChaosGL.hpp"

ChaosGL::ChaosGL ()
{
	
}

ChaosGL::~ChaosGL() {
	
}

void ChaosGL::SetUp()
{
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
	
	_window = glfwCreateWindow(640, 480, "ChaosGL Test", nullptr, nullptr);
	if (!_window) throw "Create window failed.";
	
	glfwMakeContextCurrent(_window);
}


void ChaosGL::TearDown() {
	glfwSetWindowShouldClose(_window, GL_TRUE);
	
	while (!glfwWindowShouldClose(_window)) {
		glfwSwapBuffers(_window);
		glfwPollEvents();
		chaos::info("Poll");
	}
	
	glfwDestroyWindow(_window);
}



chaosgl::VertexShader* ChaosGL::prepareVertexShader()
{
	chaosgl::VertexShader* shader = new chaosgl::VertexShader();
	shader->addSource("/Users/chaos/Development/Sources/c++/chaosarts/ChaosGL/ChaosGLTest/main.vs.glsl");
	return shader;
}


chaosgl::FragmentShader* ChaosGL::prepareFragmentShader()
{
	chaosgl::FragmentShader* shader = new chaosgl::FragmentShader();
	shader->addSource("/Users/chaos/Development/Sources/c++/chaosarts/ChaosGL/ChaosGLTest/main.fs.glsl");
	return shader;
}


chaosgl::Program* ChaosGL::prepareProgram()
{
	chaosgl::Program* program = new chaosgl::Program();
	return program;
}