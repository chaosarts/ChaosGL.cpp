/*
 * cap.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Glcap_h_
#define ChaosGL_Glcap_h_

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace chaosgl
{

		class cap
		{
		protected:
			cap(GLenum name, bool enable = true);
		public:
			
			/** Indicates whether it is enabled or not */
			GLboolean enabled;

			/** Provides the name of the capability */
			const GLenum name;

			/** Destructor */
			virtual ~cap();
		};
} /* namespace ca */

#endif /* GLCAP_H_ */
