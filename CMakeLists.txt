cmake_minimum_required(VERSION 3.23)

project("Maze Solver")

add_executable(maze_solver)

target_sources(
    maze_solver
    PRIVATE
        src/main.cpp
        src/maze.cpp
        src/maze_generator.cpp
        src/maze_visualiser.cpp
)
