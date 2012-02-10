/*
 * defs - contains program-wide definitions
 */
#ifndef DEFS_H__
#define DEFS_H__

/*
 * Define log method
 *
 * 0 - No debug output
 * 1 - Use file logging
 * 2 - Use debugger outputs
 * 3 - Use console outputs
 */

#define V_LOG 1

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