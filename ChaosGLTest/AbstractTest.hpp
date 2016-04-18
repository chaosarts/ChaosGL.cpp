//
//  AbstractTest.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 15.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGLTest_AbstractTest_hpp
#define ChaosGLTest_AbstractTest_hpp

#include <map>
#include <gtest/gtest.h>
#include <GLFW/glfw3.h>
#include <ChaosGL/ChaosGL.hpp>

class AbstractTest: public virtual testing::Test
{
public:
	AbstractTest ()
	{
		glfwInit();
		initHints();
		initWindow();
	};
	
	
	virtual std::map<int, int> getHints ()
	{
		std::map<int, int> hints;
		hints[GLFW_RESIZABLE] = GL_TRUE;
		hints[GLFW_VISIBLE] = GL_FALSE;
		hints[GLFW_CONTEXT_VERSION_MAJOR] = 3;
		hints[GLFW_CONTEXT_VERSION_MINOR] = 2;
		hints[GLFW_OPENGL_PROFILE] = GLFW_OPENGL_CORE_PROFILE;
		hints[GLFW_OPENGL_FORWARD_COMPAT] = GL_TRUE;
		return hints;
	}
	
	void initHints ()
	{
		std::map<int, int> hints = getHints();
		std::map<int, int>::iterator it = hints.begin();
		while (it != hints.end())
		{
			glfwWindowHint(it->first, it->second);
			it++;
		}
	}
	
	void initWindow ()
	{
		if (nullptr == _window)
		{
			_window = glfwCreateWindow(_windowWidth, _windowHeight, _windowTitle, nullptr, nullptr);
			glfwMakeContextCurrent(_window);
		}
	}
	
	
	virtual ~AbstractTest ()
	{
		glfwDestroyWindow(_window);
	}
protected:
	GLFWwindow* _window = nullptr;
	int _windowWidth = 640;
	int _windowHeight = 480;
	const char* _windowTitle = "ChaosGL Test";
};

#endif /* AbstractTest_h */
