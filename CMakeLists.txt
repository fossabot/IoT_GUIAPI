cmake_minimum_required(VERSION 3.6)

project(IoT_GUIAPI LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(LIST_LIB libs/List.cpp libs/Libs.h)

add_executable(IoT_GUIAPI main.cpp)

target_link_libraries(IoT_GUIAPI LIST_LIB)