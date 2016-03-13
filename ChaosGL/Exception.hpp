/*
 * Exception.h
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Exception_h_
#define ChaosGL_Exception_h_

#include <ChaosCore/Exception.h>

namespace ca
{
	namespace gl
	{

		class Exception : public ca::core::Exception
		{
		public:
			Exception(const char* message, int code, Exception* parent);
			Exception(const char* message, int code);
			Exception(const char* message);
			virtual ~Exception();
		};

	} /* namespace gl */
} /* namespace ca */

#endif /* EXCEPTION_H_ */
