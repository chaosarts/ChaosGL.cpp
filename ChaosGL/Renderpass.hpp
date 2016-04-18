/*
 * Renderpass.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Renderpass_hpp
#define ChaosGL_Renderpass_hpp

#include <vector>
#include <map>
#include "ChaosGL.hpp"

namespace chaosgl
{
	class Program;
	class Drawable;
	struct clearmask;
	struct cap;
	
	class Renderpass
	{
		
	public:
		
		/** 
		 * Renders the scene 
		 */
		void render ();
		
		
		/**
		 * Adds a new object to draw for this renderpass
		 */
		void addDrawable (Drawable* drawable);
		
		
		/**
		 * Returns all drawables added to this render pass
		 */
		std::vector<Drawable*> getDrawables ();
		
		
		/**
		 * Determines if the renderpass draws the given object
		 */
		bool hasDrawable (Drawable* drawable);
		
		
		/**
		 * Retrieves the index of the draw able within the renderpass
		 */
		int indexOf (Drawable* drawable);
		
		
		/**
		 * Removes the drawable and returns the index of it
		 * @param drawable
		 * @return The indes of the renderpass
		 */
		int removeDrawable (Drawable* drawable);
		
		
		/**
		 * Removes the drawable at given index and returns it
		 * @param index: The index of the drawable within the renderpass to delete
		 * @return The drawable
		 */
		Drawable* removeDrawable (int index);
		
		
		/**
		 * Adds a capability to use for this render pass
		 * @param cap: The GL capability to use
		 */
		void addCapability (cap* cap);
		
		
		/**
		 * Determines if the given capability has been added
		 * @param cap: The name of the capability to check
		 * @return True, when a capability has been added before, otherwise false
		 */
		bool hasCapability (GLenum name);
		
		
		/**
		 * Removes the capability from this renderpass
		 * @param cap
		 * @return The capability object
		 */
		cap* removeCapability (GLenum name);
		
		
		/**
		 * Adds a clear mask to use for this render pass
		 * @param clearmask: The GL clearmask
		 */
		void addClearmask (clearmask* clearmask);
		
		
		/**
		 * Determines if the renderpass uses the given clearmask
		 * @param clearmask
		 * @return True if the renderpass uses the clearmask, otherwise false
		 */
		bool hasClearmask (GLbitfield name);
		
		
		/**
		 * Removes the clearmask
		 */
		clearmask* removeClearmask (GLbitfield name);
		
		
		/**
		 * Destroys the renderpass
		 */
		virtual ~Renderpass();
		
	protected:
		
		/**
		 * Invokes to render the drawable objects
		 */
		virtual void _render () = 0;
		
		
		/**
		 * Will be called right before the render pass draws
		 */
		virtual void _beforeRender ();
		
		/**
		 * Will be called right after the render pass draws
		 */
		virtual void _afterRender ();
		
	private:
		
		/** Provides the program to use */
		Program* _program;
		
		/** Provides a list of bit masks to apply */
		std::map<GLbitfield, clearmask*> _clearmasks;
		
		/** Provides a list of OpenGL server-side capabilities */
		std::map<GLenum, cap*> _caps;
		
		/** Provides a list of drawable objects*/
		std::vector<Drawable*> _drawables;
	};
}

#endif /* RENDERER_H_ */
