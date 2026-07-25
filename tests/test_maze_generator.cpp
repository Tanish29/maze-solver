#include "maze.hpp"
#include "maze_generator.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("TestGenerator marks a cell as visited", "[generator][behavior]") {
    Maze maze(3, 3);
    // Ensure initially the cell is unvisited
    CHECK(maze.getCellStatus(0, 0) == false);

    RDFSIterativeGenerator generator;
    generator.generate(maze);

    REQUIRE(maze.getCellStatus(0, 0) == true);
}
