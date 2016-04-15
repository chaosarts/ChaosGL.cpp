//
// ChaosGL.h
// ChaosGL
//
// Created by Fu Lam Diep on 20.03.16.
// Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosGL_hpp 
#define ChaosGL_hpp 

#ifdef __APPLE__
#include <OpenGL/OpenGL.h> 
#include <OpenGL/gl3.h> 
#endif 

#define cimg_OS 1 
#define cimg_display 0 
#define cimg_verbosity 1 

namespace chaosgl
{
	bool init (int argc, const char** argv);
}
#endif
