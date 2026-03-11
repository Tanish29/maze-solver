#pragma once
#include <vector>

class Maze {
    public:
        Maze(int width, int height);

        // getters
        int getWidth() const;
        int getHeight() const;
        bool setCellVisited(int x, int y, bool visited);
        bool setCellWall(int x, int y, int index, bool hasWall);

    private:
        struct Cell {
            bool visited;
            bool walls[4]; // 0: top, 1: right, 2: bottom, 3: left
            Cell(): visited(false) {
                walls[0] = walls[1] = walls[2] = walls[3] = true; // all walls are initially present
            }
        };
        int width;
        int height;
        std::vector<std::vector<Cell>> maze;
};
