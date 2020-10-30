cmake_minimum_required(VERSION 3.2)
project(IoT_GUIAPI CXX)

set(CMAKE_CXX_STANDARD 11)

#Adding additional flags with address sanitizer
#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

#Add directory with datatypes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/datatypes/include/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/datatypes/)

#Add dirrectory with layout items
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/layout_items/include/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/layout_items/)

#Add dirrectory with screen emulator
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/IoT_Screen_Emulator/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/IoT_Screen_Emulator/)

#Add tests
enable_testing()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Testing/)

file(GLOB CPP_FILES *.cpp *.c)
add_executable(IoT_GUIAPI ${CPP_FILES})

target_link_libraries(IoT_GUIAPI GUIAPI_TYPES GUIAPI_LAYOUT_ITEMS IOT_SCREEN_EMULATOR)