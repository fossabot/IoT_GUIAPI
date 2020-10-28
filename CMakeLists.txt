cmake_minimum_required(VERSION 3.2)#версия с-make
project(IoT_GUIAPI CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(datatypes/)
add_subdirectory(datatypes/)

include_directories(screen_emulator/)
add_subdirectory(screen_emulator/)

enable_testing()
add_subdirectory(Testing/)

file(GLOB C_FILES *.c)
SET_SOURCE_FILES_PROPERTIES(${C_FILES} PROPERTIES LANGUAGE CXX)

file(GLOB CPP_FILES *.cpp *.c)
add_executable(IoT_GUIAPI ${CPP_FILES})

target_link_libraries(IoT_GUIAPI GUIAPI_TYPES GUIAPI_SCREEN_EMULATOR)