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
	struct cap
	{
	public:
		
		/** Provides the name of the capability */
		const GLenum name;
		
		/**
		 * Applies the capability for current 
		 */
		GLenum apply () const;
		
		
		/**
		 * Applies the default of the capability for current context
		 */
		GLenum revert () const;
		
		
		/** Destructor */
		virtual ~cap();
		
	protected:
		
		/**
		 * Creates a new server side capability
		 * @param name: The name of the capability
		 * @param enabled: Whether to en- or disable capability
		 */
		cap(GLenum name);
		
		/**
		 * Applies the capability to the current context
		 */
		virtual void _apply () const = 0;
	};
} /* namespace chaosgl */

#endif /* ChaosGL_Glcap_hpp */
