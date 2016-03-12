/*
 * cap.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Glcap_h_
#define _ChaosGL_Glcap_h_

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

namespace ca
{
	namespace gl
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

	} /* namespace gl */
} /* namespace ca */

#endif /* GLCAP_H_ */
