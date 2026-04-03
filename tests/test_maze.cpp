#include "maze.hpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <algorithm>

// Helper: pop all elements from a stack into a vector (preserves pop order: top -> back)
static std::vector<std::pair<int,int>> stackToVector(std::stack<std::pair<int,int>> s) {
    std::vector<std::pair<int,int>> out;
    while (!s.empty()) {
        out.push_back(s.top());
        s.pop();
    }
    return out;
}

TEST_CASE("Maze basic getters", "[maze][basic]") {
    Maze m(4, 3);
    REQUIRE(m.getWidth() == 4);
    REQUIRE(m.getHeight() == 3);
    REQUIRE(m.getNumCells() == 4 * 3);
}

TEST_CASE("Initial cell status and walls", "[maze][init]") {
    Maze m(2, 2);
    // All cells unvisited initially
    for (int y = 0; y < m.getHeight(); y++) {
        for (int x = 0; x < m.getWidth(); x++) {
            CHECK(m.getCellStatus(x, y) == false);
            auto walls = m.getCellWalls(x, y);
            // All four walls should be present initially
            for (int i = 0; i < 4; i++) {
                CHECK(walls[i] == true);
            }
        }
    }
}

TEST_CASE("Cell neighbours for center and corner cells", "[maze][neighbours]") {
    Maze m(3, 3);

    SECTION("Center cell has 4 neighbours") {
        auto stack = m.getCellNeighbours(1, 1);
        auto neighbours = stackToVector(stack);
        REQUIRE(neighbours.size() == 4);
        // expected neighbours (not order-dependent in this test)
        std::vector<std::pair<int,int>> expected = {
            {1,0}, {2,1}, {1,2}, {0,1}
        };
        for (auto &e : expected) {
            REQUIRE(std::find(neighbours.begin(), neighbours.end(), e) != neighbours.end());
        }
    }

    SECTION("Top-left corner has 2 neighbours (right and bottom)") {
        auto stack = m.getCellNeighbours(0, 0);
        auto neighbours = stackToVector(stack);
        REQUIRE(neighbours.size() == 2);
        REQUIRE(std::find(neighbours.begin(), neighbours.end(), std::pair<int,int>{1,0}) != neighbours.end());
        REQUIRE(std::find(neighbours.begin(), neighbours.end(), std::pair<int,int>{0,1}) != neighbours.end());
    }
}

TEST_CASE("setCellStatus valid and invalid inputs", "[maze][status]") {
    Maze m(3, 3);

    // valid set
    CHECK(m.setCellStatus(1, 1, true));
    REQUIRE(m.getCellStatus(1, 1));

    // negative coordinates should be rejected (and must not crash)
    REQUIRE(!m.setCellStatus(-1, 0, true));
    REQUIRE(!m.setCellStatus(0, -1, true));

    // sanity: other cells unchanged
    REQUIRE(!m.getCellStatus(0, 0));
    REQUIRE(!m.getCellStatus(2, 2));
}

TEST_CASE("setCellWall updates neighbour walls and validates index", "[maze][walls]") {
    Maze m(3, 3);

    // Remove right wall of (0,0) -> should also remove left wall of (1,0)
    REQUIRE(m.setCellWall(0, 0, 1, false) == true);
    const bool* walls00 = m.getCellWalls(0, 0);
    const bool* walls10 = m.getCellWalls(1, 0);
    CHECK(walls00[1] == false); // right wall removed
    CHECK(walls10[3] == false); // neighbour's left wall removed

    // Remove bottom wall of (1,0) -> should also remove top wall of (1,1)
    REQUIRE(m.setCellWall(1, 0, 2, false) == true);
    const bool* walls11 = m.getCellWalls(1, 1);
    CHECK(m.getCellWalls(1,0)[2] == false);
    CHECK(walls11[0] == false);

    // invalid indices for wall (e.g., -1 and 4) should be rejected
    CHECK(m.setCellWall(0, 0, -1, true) == false);
    CHECK(m.setCellWall(0, 0, 4, true) == false);
}

TEST_CASE("removeWall convenience wrapper", "[maze][remove]") {
    Maze m(3, 3);

    // remove wall between (0,0) and (1,0) (right neighbour)
    CHECK(m.removeWall(0, 0, 1, 0) == true);
    REQUIRE(m.getCellWalls(0,0)[1] == false);
    REQUIRE(m.getCellWalls(1,0)[3] == false);

    // remove wall between (1,1) and (1,0) (top neighbour)
    CHECK(m.removeWall(1, 1, 1, 0) == true);
    REQUIRE(m.getCellWalls(1,1)[0] == false);
    REQUIRE(m.getCellWalls(1,0)[2] == false);
}
