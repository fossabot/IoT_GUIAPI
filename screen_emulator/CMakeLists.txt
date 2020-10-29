file(GLOB SCREEN_EMULATOR *.cpp *.hpp *.c *.h)

add_library(IOT_SCREEN_EMULATOR ${SCREEN_EMULATOR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glad/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glad/include/)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

#glew32
target_link_libraries(IOT_SCREEN_EMULATOR ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} glad)