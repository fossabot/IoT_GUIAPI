file(GLOB SCREEN_EMULATOR *.cpp *.hpp *.c *.h)

add_library(GUIAPI_SCREEN_EMULATOR ${SCREEN_EMULATOR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

target_link_libraries(GUIAPI_SCREEN_EMULATOR ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})