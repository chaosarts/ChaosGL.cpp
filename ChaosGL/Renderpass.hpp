/*
 * Renderpass.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Renderpass_hpp
#define ChaosGL_Renderpass_hpp

#include <list>
#include "ChaosGL.hpp"

namespace chaosgl
{
	class Program;
	struct clearmask;
	struct cap;
	
	class Renderpass
	{
	private:
		/** Provides the program to use */
		Program* _program;
		
		/** Provides a list of bit masks to apply */
		std::list<clearmask*> _bitmasks;
		
		/** Provides a list of OpenGL server-side capabilities */
		std::list<cap*> _caps;
		
	protected:
		virtual void _render () = 0;
		
		virtual void _beforeRender () = 0;
		
		virtual void _afterRender () = 0;
	public:
		virtual ~Renderpass();
		
		void render ();
		
		void setCapability (cap* cap);
		
		void addBitmask (clearmask* bitmask);
	};
}

#endif /* RENDERER_H_ */
