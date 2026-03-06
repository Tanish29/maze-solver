#include "maze.hpp"

Maze::Maze(int width, int height) {
    this->height = height;
    this->width = width;
    // create maze
    for (int i = 0; i < height; i++) {
        std::vector<Cell> row;
        for (int j = 0; j < width; j++) {
            row.push_back(Cell());
        }
        maze.push_back(row);
    }
}

// getters
int Maze::getWidth() const {
    return width;
}

int Maze::getHeight() const {
    return height;
}

// setters
bool Maze::setCellVisited(int x, int y, bool visited) {
    if ((x < 0 || x > width) || (y < 0 || y > height)) {
        return false; // invalid coordinates
    }
    maze[y][x].visited = visited;
    return true;
}

bool Maze::setCellWall(int x, int y, int index, bool hasWall) {
    if ((x < 0 || x > width) || (y < 0 || y > height)) {
        return false; // invalid coordinates
    }
    if (index < 0 || index > 3) {
        return false; // invalid index
    }
    maze[y][x].walls[index] = hasWall;
    return true;
}
