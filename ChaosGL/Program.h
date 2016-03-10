/*
 * Program.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Program_h_
#define _ChaosGL_Program_h_

#include <vector>
#include <map>
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include <ChaosCore/core.h>
#include "Exception.h"
#include "Shader.h"

namespace ca
{
	namespace gl
	{
		class Program
		{
		private:
			/** Caches the attrib location queries */
			map<const char*, GLuint> _attribLocationCache;
			
			/** Caches the attrib location queries */
			map<const char*, GLuint> _uniformLocationCache;
			
			/** Provides the id of the program */
			GLuint _id = 0;
			
			/** Provides a list of shaders to add to the program */
			vector<GLuint> _shaders;
			
		public:
			
			/**
			 * Constructor
			 */
			Program();
	
			
			/**
			 * Destructor
			 */
			virtual ~Program();

		
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
			void attachShaders (GLuint shader);


			/**
			 * Attaches a shader wrapper object
			 * @param shader
			 */
			void attachShaders (Shader* shader);
		
			
			/**
			 * Returns the id of the program
			 * @return The id of the program
			 */
			GLuint getId ();
			
			
			/**
			 * Binds the attribute to given location
			 */
			void bindAttribLocation (GLuint index, const char* name);
			
			
			/**
			 * Gets the location of given attribute
			 */
			GLuint getAttribLocation (const char* name);
			
			
			/**
			 * Gets the location of given uniform
			 */
			GLuint getUniformLocation (const char* name);
			
			
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

} /* namespace creategl */

#endif /* PROGRAM_H_ */
