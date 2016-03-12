/*
 * Exception.h
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <ChaosCore/Exception.h>

namespace ca
{
	namespace gl
	{

		class Exception : public core::Exception
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
