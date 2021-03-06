/*
 * GLdepthbit.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Gldepthbit_hpp
#define ChaosGL_Gldepthbit_hpp

#include "clearmask.hpp"
#include "ChaosGL.hpp"

namespace chaosgl
{

		struct depthmask: public clearmask
		{
		public:
			GLclampd depth;

			depthmask(GLclampd depth = 1);

			virtual ~depthmask();

			virtual void clear ();
		};
} /* namespace ca */

#endif /* GLDEPTHBIT_H_ */
