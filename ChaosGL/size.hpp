//
//  GLsize.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 12.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef GLsize_hpp
#define GLsize_hpp

namespace ca
{
	namespace gl
	{
		template<typename T>
		struct size
		{
		public:
			T width;
			T height;
			
			size (T width, T height) : width(width), height(height) {};
		};
		
		
		typedef size<int> sizei;
		typedef size<float> sizef;
	}
}
#endif /* GLsize_hpp */
