cmake_minimum_required(VERSION 3.16)

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

# test
option(BUILD_TESTING "Enable testing and build tests" ON)
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(src)
    add_subdirectory(tests)
endif()
