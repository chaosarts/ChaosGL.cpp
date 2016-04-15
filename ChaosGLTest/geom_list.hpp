//
//  geom_list.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 15.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGLTest_geom_list_hpp
#define ChaosGLTest_geom_list_hpp

#include <ChaosGL/geom.hpp>
#include <glm/glm.hpp>
#include <gtest/gtest.h>

class geom_list: public virtual testing::Test
{
public:
	
	chaosgl::geom pyramide;
	
	void SetUp ()
	{
		pyramide.addValue(glm::vec3(-1, 0, -1));
		pyramide.addValue(glm::vec3(0, 0, 1));
		pyramide.addValue(glm::vec3(1, 0, -1));
		
		pyramide.addValue(glm::vec3(-1, 0, -1));
		pyramide.addValue(glm::vec3(0, 0, 1));
		pyramide.addValue(glm::vec3(0, 1, 0));
		
		pyramide.addValue(glm::vec3(0, 0, 1));
		pyramide.addValue(glm::vec3(1, 0, -1));
		pyramide.addValue(glm::vec3(0, 1, 0));
		
		pyramide.addValue(glm::vec3(1, 0, -1));
		pyramide.addValue(glm::vec3(-1, 0, -1));
		pyramide.addValue(glm::vec3(0, 1, 0));
	}
	
	void TearDown ()
	{
		
	}
	
	virtual ~geom_list ()
	{
		
	}
};


TEST_F (geom_list, base)
{
	ASSERT_EQ(12, pyramide.count(GL_ARRAY_BUFFER));
	ASSERT_EQ(4, pyramide.count(GL_ELEMENT_ARRAY_BUFFER));
}


TEST_F (geom_list, primitve)
{
	ASSERT_EQ(4, pyramide.getTriangleCount());
	
	const std::vector<chaosgl::triangle3> triangles = pyramide.getTriangles(glm::vec3(0, 1, 0));
	ASSERT_EQ(3, triangles.size());
	
	ASSERT_EQ(glm::vec3(-1, 0, -1), triangles[0].a);
	ASSERT_EQ(glm::vec3(0, 0, 1), triangles[0].b);
	ASSERT_EQ(glm::vec3(0, 1, 0), triangles[0].c);
	
	ASSERT_EQ(glm::vec3(0, 0, 1), triangles[1].a);
	ASSERT_EQ(glm::vec3(1, 0, -1), triangles[1].b);
	ASSERT_EQ(glm::vec3(0, 1, 0), triangles[1].c);
	
	ASSERT_EQ(glm::vec3(1, 0, -1), triangles[2].a);
	ASSERT_EQ(glm::vec3(-1, 0, -1), triangles[2].b);
	ASSERT_EQ(glm::vec3(0, 1, 0), triangles[2].c);
	
	
	const chaosgl::triangle3 triangle = pyramide.getTriangle(0);
	ASSERT_EQ(glm::vec3(-1, 0, -1), triangle.a);
	ASSERT_EQ(glm::vec3(0, 0, 1), triangle.b);
	ASSERT_EQ(glm::vec3(1, 0, -1), triangle.c);
}

#endif /* geom_list_h */
