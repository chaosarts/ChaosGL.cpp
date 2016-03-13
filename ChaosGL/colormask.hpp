/*
 * GLcolorbit.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Glcolorbit_h_
#define ChaosGL_Glcolorbit_h_

#include "clearmask.hpp"

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
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

	} /* namespace gl */
} /* namespace ca */

#endif /* GLCOLORBIT_H_ */
