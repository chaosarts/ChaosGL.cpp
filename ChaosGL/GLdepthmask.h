/*
 * GLdepthbit.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Gldepthbit_h_
#define _ChaosGL_Gldepthbit_h_

#include "GLclearmask.h"

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
	{

		struct GLdepthmask: public GLclearmask
		{
		public:
			GLclampd depth;

			GLdepthmask(GLclampd depth = 1);

			virtual ~GLdepthmask();

			virtual void clear ();
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* GLDEPTHBIT_H_ */
