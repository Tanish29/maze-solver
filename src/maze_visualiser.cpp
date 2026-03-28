#include "maze_visualiser.hpp"
#include <iostream>

namespace MazeVisualiser {
    void printMaze(const Maze& maze) {
        int numRows = maze.getHeight();
        int numCols = maze.getWidth();

        // print maze
        for (int y = 0; y < numRows; y++) {
            // top walls
            for (int x = 0; x < numCols; x++) {
                auto walls = maze.getCellWalls(x, y);
                std::cout << "*";
                std::cout << (walls[0] ? "---" : "   ");
            }
            std::cout << ("*\n"); // end corner

            // left walls
            for (int x = 0; x < numCols; x++) {
                auto walls = maze.getCellWalls(x, y);
                std::cout << (walls[3] ? "|" : " ");
                std::cout << ("   "); // cell space
            }
            std::cout << ("|\n"); // end wall
        }

        // bottom border walls
        for (int x = 0; x < numCols; x++) {
            auto walls = maze.getCellWalls(x, numRows - 1);
            std::cout << ("*");
            std::cout << (walls[2] ? "---" : "   ");
        }
        std::cout << ("*\n"); // last corner
    }
}
