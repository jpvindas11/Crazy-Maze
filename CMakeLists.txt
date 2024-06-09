cmake_minimum_required(VERSION 3.0.0)
project(CrazyMaze VERSION 0.1.0 LANGUAGES C CXX)

find_package(SDL2 REQUIRED)

set(SDL2_IMAGE_INCLUDE_DIRS "/usr/include/SDL2")
set(SDL2_IMAGE_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2_image.so")

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp" "src/level/*.cpp" )

list(APPEND SOURCES "src/cell.cpp")

add_executable(CrazyMaze ${SOURCES})

target_link_libraries(CrazyMaze ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


