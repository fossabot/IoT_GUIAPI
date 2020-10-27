file(GLOB SCREEN_EMULATOR *.cpp *.hpp *.c *.h)

add_library(GUIAPI_SCREEN_EMULATOR ${SCREEN_EMULATOR})

add_subdirectory(glad/)
include_directories(glad/include/)

#set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(glfw3 REQUIRED)
#find_package(GLEW REQUIRED)
#include_directories(${GLEW_INCLUDE_DIRS})
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

#glew32
target_link_libraries(GUIAPI_SCREEN_EMULATOR ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} glad)