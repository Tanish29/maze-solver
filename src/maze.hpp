#pragma once
#include <vector>

class Maze {
    public:
        Maze(int width, int height);

        // getters
        int getNumCells() const;
        int getWidth() const;
        int getHeight() const;
        bool getCellStatus(int x, int y) const;
        std::stack<std::pair<int, int>> getCellNeighbours(int x, int y) const;
        // setters/writers
        bool setCellStatus(int x, int y, bool visited);
        bool setCellWall(int x, int y, int index, bool hasWall);
        bool removeWall(int x1, int y1, int x2, int y2);

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
