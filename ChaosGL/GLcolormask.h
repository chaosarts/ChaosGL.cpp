/*
 * GLcolorbit.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Glcolorbit_h_
#define _ChaosGL_Glcolorbit_h_

#include "GLclearmask.h"

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
	{

		struct GLcolormask : public GLclearmask
		{
		public:
			GLclampf red = 0;
			GLclampf green = 0;
			GLclampf blue = 0;
			GLclampf alpha = 1;

			GLcolormask(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha = 1);
			GLcolormask(GLclampf value, GLclampf alpha = 1);
			GLcolormask(GLclampf alpha = 1);
			virtual ~GLcolormask();
			virtual void clear();
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* GLCOLORBIT_H_ */
