cmake_minimum_required(VERSION 3.2)
project(IoT_GUIAPI CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/datatypes/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/datatypes/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/IoT_Screen_Emulator/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/IoT_Screen_Emulator/)

enable_testing()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Testing/)

file(GLOB CPP_FILES *.cpp *.c)
add_executable(IoT_GUIAPI ${CPP_FILES})

target_link_libraries(IoT_GUIAPI GUIAPI_TYPES IOT_SCREEN_EMULATOR)