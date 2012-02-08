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

/*********************************************
 * DO NOT EDIT PAST THIS LINE
 ********************************************/

/*
 * Error Codes
 */
#define V_SUCCESS				0x00

#define V_ERR_OGL_GLFWINIT		0x01

#endif