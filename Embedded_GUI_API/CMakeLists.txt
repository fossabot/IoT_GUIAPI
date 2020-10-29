cmake_minimum_required(VERSION 3.2) #cmake version
project(Embeeded_GUI_API CXX)       #Project name and target language

set(CMAKE_CXX_STANDARD 11)          #Set c++ standart

#Add subdirrectory with screen emulator
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../IoT_Screen_Emulator/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../IoT_Screen_Emulator/ ${CMAKE_CURRENT_BINARY_DIR}/IoT_Screen_Emulator/)

#enable_testing()
#add_subdirectory(Testing/)

#Add properties for C filex
file(GLOB C_FILES *.c *.h)
SET_SOURCE_FILES_PROPERTIES(${C_FILES} PROPERTIES LANGUAGE CXX)

file(GLOB CPP_FILES *.cpp *.c *.h)
add_executable(Embeeded_GUI_API ${CPP_FILES})

#Link libraries to executable
target_link_libraries(Embeeded_GUI_API IOT_SCREEN_EMULATOR)