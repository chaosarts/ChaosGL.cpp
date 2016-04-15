/*
 * GLcolorbit.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Glcolorbit_hpp
#define ChaosGL_Glcolorbit_hpp

#include "clearmask.hpp"
#include "ChaosGL.hpp"

namespace chaosgl
{

		struct colormask : public clearmask
		{
		public:
			GLclampf red = 0;
			GLclampf green = 0;
			GLclampf blue = 0;
			GLclampf alpha = 1;

			colormask(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha = 1);
			colormask(GLclampf value, GLclampf alpha = 1);
			colormask(GLclampf alpha = 1);
			virtual ~colormask();
			virtual void clear();
		};
} /* namespace ca */

#endif /* GLCOLORBIT_H_ */
