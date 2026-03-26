#include "maze.hpp"
#include "maze_visualiser.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("maze visualiser", "[visualise]") {
    Maze maze(5,5);
    MazeVisualiser::printMaze(maze);
    REQUIRE(true);
}
