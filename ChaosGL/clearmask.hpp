/*
 * GLbitmask.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_clearmask_h_
#define ChaosGL_clearmask_h_

#include <OpenGL/gl.h>

namespace chaosgl
{
		struct clearmask
		{
		protected:
			clearmask (GLbitfield field);
		public:
			const GLbitfield field;
			virtual void clear () = 0;
			virtual ~clearmask();
		};
} /* namespace ca */

#endif /* GLBITMASK_H_ */
