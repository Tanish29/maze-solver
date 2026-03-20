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
int Maze::getNumCells() const {
    return height * width;
}

int Maze::getWidth() const {
    return width;
}

int Maze::getHeight() const {
    return height;
}

bool Maze::getCellStatus(int x, int y) const {
    return maze[y][x].visited;
}

std::stack<std::pair<int, int>> Maze::getCellNeighbours(int x, int y) const {
    std::stack<std::pair<int, int>> neighbours;
    // top
    if (y > 0) {
        neighbours.push({x, y-1});
    }
    // right
    if (x < width - 1) {
        neighbours.push({x+1, y});
    }
    // bottom
    if (y < height - 1) {
        neighbours.push({x, y+1});
    }
    // left
    if (x > 0) {
        neighbours.push({x-1, y});
    }
    return neighbours;
}

// setters/writers
bool Maze::setCellStatus(int x, int y, bool visited) {
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
    // set neighbour cell wall
    if (index == 0) {
        maze[y-1][x].walls[2] = hasWall;
    } else if (index == 1) {
        maze[y][x+1].walls[3] = hasWall;
    } else if (index == 2) {
        maze[y+1][x].walls[0] = hasWall;
    } else if (index == 3) {
        maze[y][x-1].walls[1] = hasWall;
    }
    return true;
}
