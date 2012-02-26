/*
 * defs - contains program-wide definitions
 */
#ifndef DEFS_H__
#define DEFS_H__

#include "gl/glew.h"
#include "gl/glfw.h"

/*
 * Define log method
 *
 * 0 - No debug output
 * 1 - Use file logging
 * 2 - Use debugger outputs
 * 3 - Use console outputs
 */

#define V_LOG 3

/*
 * Define console scrollback length (in lines)
 */
#define V_CONSOLE_SCROLLBACK 1000

/*
 * Define Window Title
 */
#define V_WINDOW_TITLE "Vexal Online"

/*
 * Define Anti-Aliasing
 */
#define V_OGL_ANTIALIAS 4

/*
 * Define Window Size
 */
#define V_OGL_WINDOW_W 800
#define V_OGL_WINDOW_H 600

/*********************************************
 * DO NOT EDIT PAST THIS LINE
 ********************************************/

/*
 * The window mode
 *
 * Values can be:
 *  GLFW_WINDOW
 *  GLFW_WINDOW_NO_RESIZE (broken)
 *  GLFW_FULLSCREEN
 * 
 */
#define V_OGL_WINMODE GLFW_WINDOW

/*
 * Voxel loading/memory values
 */
#define V_BITMEM_GRID 3
#define V_BITMEM_TOTAL V_BITMEM_GRID * V_BITMEM_GRID

#define V_BITMEM_BITSIZE 256
#define V_BITMEM_BITSIZEM1 V_BITMEM_BITSIZE-1
#define V_BITMEM_VTOTAL V_BITMEM_BITSIZE * V_BITMEM_BITSIZE * V_BITMEM_BITSIZE

/*
 * Error Codes
 */
#define V_SUCCESS				0x00

#define V_ERR_OGL_GLFWINIT		0x01
#define V_ERR_OGL_WINDOW		0x02
#define V_ERR_OGL_GLEWINIT		0x03

/*
 * Placeholder Operating System Macros
 *
 * This section allows us to change the default
 * system macros defined for each compiler
 */
#if defined(_WIN32)
#define VWIN32
#elif defined(LINUX)
#define VLINUX
#elif defined(__APPLE__)
#define VAPPLE
#endif

#endif