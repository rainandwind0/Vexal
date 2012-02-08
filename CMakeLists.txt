 add_definitions(
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

set(GLFW_SOURCE	
	glfw/lib/enable.c 
	glfw/lib/fullscreen.c 
	glfw/lib/glext.c 
	glfw/lib/image.c 
	glfw/lib/init.c 
	glfw/lib/input.c 
	glfw/lib/joystick.c 
	glfw/lib/stream.c 
	glfw/lib/tga.c 
	glfw/lib/thread.c 
	glfw/lib/time.c 
	glfw/lib/window.c
)


if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
set(GLFW_SOURCE	${GLFW_SOURCE}
	glfw/lib/win32/win32_enable.c 
	glfw/lib/win32/win32_fullscreen.c 
	glfw/lib/win32/win32_glext.c 
	glfw/lib/win32/win32_init.c 
	glfw/lib/win32/win32_joystick.c 
	glfw/lib/win32/win32_thread.c 
	glfw/lib/win32/win32_time.c 
	glfw/lib/win32/win32_window.c 
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(GLFW_SOURCE	${GLFW_SOURCE}
	glfw/lib/x11/x11_enable.c 
	glfw/lib/x11/x11_fullscreen.c 
	glfw/lib/x11/x11_glext.c 
	glfw/lib/x11/x11_init.c 
	glfw/lib/x11/x11_joystick.c 
	glfw/lib/x11/x11_keysym2unicode.c 
	glfw/lib/x11/x11_thread.c 
	glfw/lib/x11/x11_time.c 
	glfw/lib/x11/x11_window.c
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(GLFW_SOURCE	${GLFW_SOURCE}
	glfw/lib/cocoa/cocoa_enable.c 
	glfw/lib/cocoa/cocoa_fullscreen.c 
	glfw/lib/cocoa/cocoa_glext.c 
	glfw/lib/cocoa/cocoa_init.c 
	glfw/lib/cocoa/cocoa_joystick.c 
	glfw/lib/cocoa/cocoa_thread.c 
	glfw/lib/cocoa/cocoa_time.c 
	glfw/lib/cocoa/cocoa_window.c 
)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")


if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
set(GLFW_HEADERS
	glfw/lib/win32/platform.h
	glfw/lib/internal.h
)
include_directories(
	glfw/lib/win32/
	glfw/lib/
	glfw/include/
	glew/include/
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(GLFW_HEADERS
	glfw/lib/x11/platform.h
	glfw/lib/internal.h
)
include_directories(
	glfw/lib/x11/
	glfw/lib/
	glfw/include/
	glew/include/
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(GLFW_HEADERS
	glfw/lib/cocoa/platform.h
	glfw/lib/internal.h
)
include_directories(
	glfw/lib/cocoa/
	glfw/lib/
	glfw/include/
	glew/include/
)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")


add_library( GLFW STATIC
	${GLFW_SOURCE}
	${GLFW_HEADERS}
)

target_link_libraries(GLFW
	${OPENGL_LIBRARY}
)



set(GLEW_SOURCE
	glew/src/glew.c
)

set(GLEW_HEADERS
)


add_library( GLEW STATIC
	${GLEW_SOURCE}
	${GLEW_INCLUDE}
)

target_link_libraries(GLEW
	${OPENGL_LIBRARY}
)

