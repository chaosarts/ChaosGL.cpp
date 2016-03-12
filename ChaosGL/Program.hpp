/*
 * Program.h
 *
 *  Created on: 07.03.2016
 *      Author: chaos
 */

#ifndef _ChaosGL_Program_h_
#define _ChaosGL_Program_h_

#ifndef ATTRIBLOC_START
#define ATTRIBLOC_START 0;
#endif

#define ATTRIBLOC_POSITION ATTRIBLOC_START + 0
#define ATTRIBLOC_NORMAL ATTRIBLOC_START + 1
#define ATTRIBLOC_COLOR ATTRIBLOC_START + 2
#define ATTRIBLOC_TANGENT ATTRIBLOC_START + 3
#define ATTRIBLOC_BITANGENT ATTRIBLOC_START + 4
#define ATTRIBLOC_TEXCOORD0 ATTRIBLOC_START + 5
#define ATTRIBLOC_TEXCOORD1 ATTRIBLOC_START + 6
#define ATTRIBLOC_TEXCOORD2 ATTRIBLOC_START + 7
#define ATTRIBLOC_TEXCOORD3 ATTRIBLOC_START + 8
#define ATTRIBLOC_TEXCOORD4 ATTRIBLOC_START + 9
#define ATTRIBLOC_TEXCOORD5 ATTRIBLOC_START + 10
#define ATTRIBLOC_TEXCOORD6 ATTRIBLOC_START + 11
#define ATTRIBLOC_TEXCOORD7 ATTRIBLOC_START + 12
#define ATTRIBLOC_TEXCOORD8 ATTRIBLOC_START + 13
#define ATTRIBLOC_TEXCOORD9 ATTRIBLOC_START + 14
#define ATTRIBLOC_TEXCOORD10 ATTRIBLOC_START + 15
#define ATTRIBLOC_TEXCOORD11 ATTRIBLOC_START + 16
#define ATTRIBLOC_TEXCOORD12 ATTRIBLOC_START + 17
#define ATTRIBLOC_TEXCOORD13 ATTRIBLOC_START + 18
#define ATTRIBLOC_TEXCOORD14 ATTRIBLOC_START + 19
#define ATTRIBLOC_TEXCOORD15 ATTRIBLOC_START + 20
#define ATTRIBLOC_TEXCOORD16 ATTRIBLOC_START + 21
#define ATTRIBLOC_TEXCOORD17 ATTRIBLOC_START + 22
#define ATTRIBLOC_TEXCOORD18 ATTRIBLOC_START + 23
#define ATTRIBLOC_TEXCOORD19 ATTRIBLOC_START + 24
#define ATTRIBLOC_TEXCOORD20 ATTRIBLOC_START + 25
#define ATTRIBLOC_TEXCOORD21 ATTRIBLOC_START + 26
#define ATTRIBLOC_TEXCOORD22 ATTRIBLOC_START + 27
#define ATTRIBLOC_TEXCOORD23 ATTRIBLOC_START + 28
#define ATTRIBLOC_TEXCOORD24 ATTRIBLOC_START + 29
#define ATTRIBLOC_TEXCOORD25 ATTRIBLOC_START + 30
#define ATTRIBLOC_TEXCOORD26 ATTRIBLOC_START + 31
#define ATTRIBLOC_TEXCOORD27 ATTRIBLOC_START + 32
#define ATTRIBLOC_TEXCOORD28 ATTRIBLOC_START + 33
#define ATTRIBLOC_TEXCOORD29 ATTRIBLOC_START + 34
#define ATTRIBLOC_TEXCOORD30 ATTRIBLOC_START + 35
#define ATTRIBLOC_TEXCOORD31 ATTRIBLOC_START + 36
#define ATTRIBLOC_TEXCOORD32 ATTRIBLOC_START + 38
#define ATTRIBLOC_END ATTRIBLOC_START + 38

#include <vector>
#include <map>
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include <ChaosCore/core.h>
#include "Exception.hpp"
#include "Shader.hpp"

namespace ca
{
	namespace gl
	{
		class Program
		{
		private:
			
			/** Provides the id of the program */
			GLuint _id = 0;
			
			/** Caches attribute locations */
			map<const char*, GLuint> _attribLocationCache;
			
			/** Caches uniform locations */
			map<const char*, GLuint> _uniformLocationCache;
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
			void attachShader (GLuint shader);


			/**
			 * Attaches a shader wrapper object
			 * @param shader
			 */
			void attachShader (Shader* shader);
			
			
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

} /* namespace creategl */

#endif /* PROGRAM_H_ */
