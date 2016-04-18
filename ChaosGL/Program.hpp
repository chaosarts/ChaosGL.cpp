/*
 * Program.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef ChaosGL_Program_hpp
#define ChaosGL_Program_hpp


#include <vector>
#include <map>
#include "ChaosGL.hpp"

namespace chaosgl
{
	class Shader;
	class Program
	{
	private:
		
		/** Provides the id of the program */
		GLuint _id = 0;
		
		/** Caches attribute locations */
		std::map<const char*, GLuint> _attribLocationCache;
		
		/** Caches uniform locations */
		std::map<const char*, GLuint> _uniformLocationCache;
	public:
		
		/**
		 * Returns the program, that is currently in use
		 * @return The id of the Program
		 */
		static GLint current ();
		
		
		/**
		 * Returns the according Program object
		 * @param id: The id of the program
		 */
		static Program* get (GLuint id);
		
		/**
		 * Constructor
		 */
		Program ();
		
		
		/**
		 * Destructor
		 */
		virtual ~Program();
		
		
		/**
		 * Returns the id of the program
		 * @return The id of the program
		 */
		GLuint getId ();
		
		
		/**
		 * Links the program
		 */
		GLint link ();
		
		/**
		 * Makes the program current
		 */
		GLint use ();
		
		/**
		 * Attaches a native OpenGL shader to the program
		 * @param shader
		 */
		GLenum attachShader (GLuint shader);
		
		
		/**
		 * Attaches a shader wrapper object
		 * @param shader
		 */
		GLenum attachShader (Shader* shader);
		
		
		/**
		 * Detaches the shader from the program
		 * @param shader
		 */
		void detachShader (GLuint shader);
		
		
		/**
		 * Detaches the shader from the program
		 * @param shader
		 */
		void detachShader (Shader* shader);
		
		
		/**
		 * Binds the attribute to given location
		 */
		void bindAttribLocation (GLuint index, const char* name);
		
		
		/**
		 * Gets the location of given attribute
		 */
		GLint getAttribLocation (const char* name);
		
		
		/**
		 * Gets the location of given uniform
		 */
		GLint getUniformLocation (const char* name);
		
		
		/**
		 * Returns the info log
		 */
		const char* getInfoLog ();
		
		/**
		 * Determines if program is a program
		 */
		GLboolean isProgram ();
		
		/**
		 * Returns the parameter value of given parameter name
		 * @return
		 */
		GLint getParam (GLenum pname);
		
		
		/**
		 * Short cut for getParam(GL_LINK_STATUS)
		 */
		GLint getLinkStatus ();
		
		
		/**
		 * Short cut for getParam(GL_DELETE_STATUS)
		 */
		GLint getDeleteStatus ();
		
		
		/**
		 * Short cut for getParam(GL_VALIDATE_STATUS)
		 */
		GLint getValidateStatus ();
		
		
		/**
		 * Shortcut for getParam(GL_INFO_LOG_LENGTH)
		 */
		GLint getInfoLogLength ();
		
		
		/**
		 * Short cut for getParam(GL_ATTACHED_SHADERS)
		 */
		GLint getAttachedShaders ();
		
		
		/**
		 * Short cut for getParam(GL_ACTIVE_ATTRIBUTES)
		 */
		GLint getActiveAttributes ();
		
		
		/**
		 * Short cut for getParam(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH)
		 */
		GLint getActiveAttributeMaxLength ();
		
		
		/**
		 * Short cut for getParam(GL_ACTIVE_ATTRIBUTES)
		 */
		GLint getActiveUniforms ();
		
		
		/**
		 * Short cut for getParam(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH)
		 */
		GLint getActiveUniformMaxLength ();
	};
}

#endif
