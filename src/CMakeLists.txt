cmake_minimum_required(VERSION 3.16)

add_library(maze_lib
    maze.cpp
    maze_generator.cpp
    maze_visualiser.cpp
)

target_include_directories(maze_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
