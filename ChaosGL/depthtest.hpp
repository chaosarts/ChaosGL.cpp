//
//  depthcap.hpp
//  ChaosGL
//
//  Created by Fu Lam Diep on 18.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_depthcap_hpp
#define ChaosGL_depthcap_hpp

#include "cap.hpp"
#include "ChaosGL.hpp"

namespace chaosgl
{
	struct depthtest : public virtual cap
	{
	public:
		
		/** Provides the compare function to use for depth test */
		GLenum func;
		
		/**
		 * Creates a depth test capability
		 * @param func: The function to use for comparsion
		 */
		depthtest (GLenum func);
		
		/**
		 * Creates a depth test capability with default values
		 */
		depthtest ();
	protected:
		
		/**
		 * @see chaosgl::cap::_apply
		 */
		virtual void _apply() const;
	};
}

#endif /* depthcap_hpp */
