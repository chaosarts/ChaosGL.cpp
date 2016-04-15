/*
 * Exception.h
 *
 *  Created on: 08.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Exception_hpp
#define ChaosGL_Exception_hpp

#include <ChaosCore/Exception.hpp>

namespace chaosgl
{

		class Exception : public chaos::Exception
		{
		public:
			Exception(const char* message, int code, Exception* parent);
			Exception(const char* message, int code);
			Exception(const char* message);
			virtual ~Exception();
		};
} /* namespace ca */

#endif /* EXCEPTION_H_ */
