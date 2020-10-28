file(GLOB SCREEN_EMULATOR *.cpp *.hpp *.c *.h)

add_library(GUIAPI_SCREEN_EMULATOR ${SCREEN_EMULATOR})

add_subdirectory(glad/)
include_directories(glad/include/)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

#glew32
target_link_libraries(GUIAPI_SCREEN_EMULATOR ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} glad)