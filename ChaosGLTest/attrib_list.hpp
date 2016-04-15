//
//  attrib_test.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 15.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGLTest_attrib_test_hpp
#define ChaosGLTest_attrib_test_hpp

#include <ChaosGL/attrib.hpp>
#include <glm/glm.hpp>
#include <gtest/gtest.h>


class attrib_list: public virtual testing::Test
{
public:
	
	void SetUp ()
	{
		
	}
	
	void TearDown ()
	{
		
	}
	
	virtual ~attrib_list ()
	{
		
	}
	
	
	chaosgl::tattrib_list<glm::vec3> values;
};


TEST_F(attrib_list, values)
{
	values.addValue(glm::vec3(1, 0, 0));
	values.addValue(glm::vec3(0, 1, 0));
	values.addValue(glm::vec3(0, 0, 1));
	values.addValue(glm::vec3(0, 1, 1));
	values.addValue(glm::vec3(0, 1, 0));
	values.addValue(glm::vec3(1, 0, 1));
	values.addValue(glm::vec3(1, 0, 0));
	
	std::vector<int> indexlist({0, 1, 2, 3, 1, 4, 0});
	
	ASSERT_EQ(values.count(), 7);
	ASSERT_EQ(values.count(GL_ELEMENT_ARRAY_BUFFER), 5);
	ASSERT_EQ(values.getIndexList(), indexlist);
	ASSERT_EQ(values.indexOf(glm::vec3(0, 1, 0)), 1);
	ASSERT_EQ(values.indexOf(glm::vec3(0, 1, 1)), 3);
}


#endif /* ChaosGLTest_attrib_list_hpp */
