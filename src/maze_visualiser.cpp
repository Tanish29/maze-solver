#include "maze_visualiser.hpp"
#include <cstdio>

namespace MazeVisualiser {
    void printMaze(const Maze& maze) {
        int numRows = maze.getHeight();
        int numCols = maze.getWidth();

        // print maze
        for (int y = 0; y < numRows; y++) {
            // top walls
            for (int x = 0; x < numCols; x++) {
                auto walls = maze.getCellWalls(x, y);
                printf(walls[0] ? "-" : " ");
            }
            // bottom walls
            for (int x = 0; x < numCols; x++) {
                auto walls = maze.getCellWalls(x, y);
                printf(walls[3] ? "|" : " ");
            }
            printf("|\n");
        }
    }
}
