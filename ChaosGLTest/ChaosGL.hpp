//
//  Base.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 08.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Base_hpp
#define Base_hpp

#include <stdio.h>
#include <gtest/gtest.h>
#include <GLFW/glfw3.h>
#include <ChaosCore/core.h>
#include "ChaosGL/Shader.h"
#include "ChaosGL/VertexShader.h"
#include "ChaosGL/FragmentShader.h"
#include "ChaosGL/Program.h"
#include "ChaosGL/Buffer.h"

class ChaosGL : public testing::Test
{
protected:
	GLFWwindow* _window;
	void SetUp ();
	void TearDown ();
public:
	ChaosGL();
	
	virtual ~ChaosGL ();
	
	static ca::gl::VertexShader* prepareVertexShader ();
	
	static ca::gl::FragmentShader* prepareFragmentShader ();
	
	static ca::gl::Program* prepareProgram ();
};
#endif /* Base_hpp */
