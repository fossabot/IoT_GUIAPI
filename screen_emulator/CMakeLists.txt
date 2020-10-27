file(GLOB SCREEN_EMULATOR *.cpp *.hpp *.c *.h)

add_library(GUIAPI_SCREEN_EMULATOR ${SCREEN_EMULATOR})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(glfw3 REQUIRED)
#include_directories(${GLFW_INCLUDE_DIRS})
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

target_link_libraries(GUIAPI_SCREEN_EMULATOR ${OPENGL_LIBRARIES} glew32 glfw ${GLFW_LIBRARIES} Threads::Threads)