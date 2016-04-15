//
//  tbasis3.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 15.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGLTest_tbasis3_hpp
#define ChaosGLTest_tbasis3_hpp

#include <ChaosGL/basis.hpp>
#include <gtest/gtest.h>

class basis : public virtual testing::Test
{
public:
	chaosgl::basis3 basis3_0;
	chaosgl::basis3 basis3_1;
	
	void SetUp ()
	{
		basis3_0 = chaosgl::basis3(glm::vec3(1, 1, 0), glm::vec3(1, 0, 1), glm::vec3(0, 1, 1));
		basis3_1 = chaosgl::basis3(glm::vec3(1, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0, 1));
	}
	
	
	void TearDown ()
	{
		
	}
	
	
	virtual ~basis ()
	{
		
	}
};


TEST_F (basis, normalize)
{
	chaosgl::basis3 helpBasis3;
	
	helpBasis3 = chaosgl::normalize(basis3_0);
	ASSERT_EQ(glm::normalize(glm::vec3(1, 1, 0)), helpBasis3.x);
	
	/// Tolerating deviation due to rounding errors
	helpBasis3 = chaosgl::orthonormalize(basis3_0);
	ASSERT_GE(3e-8, glm::dot(helpBasis3.x, helpBasis3.y));
	ASSERT_GE(3e-8, glm::dot(helpBasis3.x, helpBasis3.z));
	ASSERT_GE(3e-8, glm::dot(helpBasis3.y, helpBasis3.z));
	
}


TEST_F (basis, transition)
{
	glm::mat3x3 transition;
	
	transition = chaosgl::transitionMatrix(basis3_0, basis3_1);
	ASSERT_EQ(glm::vec3(0, 1, -1), transition[0]);
	ASSERT_EQ(glm::vec3(1, 0, 1), transition[1]);
	ASSERT_EQ(glm::vec3(-1, 1, 0), transition[2]);
	
	transition = chaosgl::transitionMatrix(basis3_1, basis3_0);
	ASSERT_EQ(glm::vec3(.5f, .5f, -.5f), transition[0]);
	ASSERT_EQ(glm::vec3(.5f, .5f, .5f), transition[1]);
	ASSERT_EQ(glm::vec3(-.5f, .5f, .5f), transition[2]);
}

#endif /* tbasis3_h */
