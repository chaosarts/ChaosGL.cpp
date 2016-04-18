//
//  Shader.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 15.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGLTest_Shader_hpp
#define ChaosGLTest_Shader_hpp

#include "AbstractTest.hpp"
#include "Externs.hpp"
#include <ChaosGL/VertexShader.hpp>
#include <ChaosGL/FragmentShader.hpp>

class Shader: public virtual AbstractTest
{
public:
	chaosgl::Shader* vertShader;
	chaosgl::Shader* fragShader;
	
	void SetUp ()
	{
		vertShader = new chaosgl::VertexShader();
		vertShader->addSource((const char*) base_vertex_glsl, base_vertex_glsl_len);
		
		fragShader = new chaosgl::FragmentShader();
		fragShader->addSource((const char*) base_fragment_glsl, base_fragment_glsl_len);
	}
	
	
	virtual ~Shader ()
	{
		delete vertShader;
		delete fragShader;
	}
};


TEST_F (Shader, Base)
{
	ASSERT_EQ(GL_NO_ERROR, vertShader->init());
	ASSERT_NE(GL_NO_ERROR, vertShader->getId());
	ASSERT_EQ(GL_VERTEX_SHADER, vertShader->getParam(GL_SHADER_TYPE));
	ASSERT_EQ(GL_FALSE, vertShader->getCompileStatus());
	ASSERT_EQ(GL_NO_ERROR, vertShader->compile());
	ASSERT_EQ(GL_TRUE, vertShader->getCompileStatus());
}

#endif /* Shader_h */
