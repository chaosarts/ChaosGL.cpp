/*
 * cap.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Glcap_hpp
#define ChaosGL_Glcap_hpp

#include "ChaosGL.hpp"

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
