/*
 * GLbitmask.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_clearmask_hpp
#define ChaosGL_clearmask_hpp

#include "ChaosGL.hpp"

namespace chaosgl
{
	struct clearmask
	{
	public:
		const GLbitfield field;
		
		
		/**
		 *
		 */
		virtual void clear () = 0;
		
		
		/**
		 * Destroys the clearmask
		 */
		virtual ~clearmask();
		
	protected:
		/**
		 * Creates a new clear mask for given field
		 * @param field
		 */
		clearmask (GLbitfield field);
	};
} /* namespace ca */

#endif /* ChaosGL_clearmask_hpp */
