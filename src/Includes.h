#ifndef _INCLUDES_H
#define _INCLUDES_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <fstream>
#include <stdlib.h> /* for exit */

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define SIMPLEBMP_OPENGL
#include "simplebmp.h"

#define Log(x) (std::cout << x << std::endl)
#define TO_RADIANS 3.141592 / 180.0

#endif