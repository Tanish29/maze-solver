#include "maze_visualiser.hpp"
#include <iostream>
#include <string>

namespace MazeVisualiser {
    void printMaze(const Maze& maze) {
        int numRows = maze.getHeight();
        int numCols = maze.getWidth();
        // auto top_wall_char = "-";
        auto spacing = 3;
        auto top_wall = std::string(spacing, '-');
        auto left_wall = std::string("|");
        auto corner = std::string("*");
        auto cell_space = std::string(spacing, ' ');

        // print maze
        for (int y = 0; y < numRows; y++) {
            // top walls
            for (int x = 0; x < numCols; x++) {
                auto walls = maze.getCellWalls(x, y);
                std::cout << corner << (walls[0] ? top_wall : cell_space);
            }
            std::cout << corner << "\n"; // end corner

            // left walls
            for (int x = 0; x < numCols; x++) {
                auto walls = maze.getCellWalls(x, y);
                std::cout << (walls[3] ? left_wall : " ");
                std::cout << cell_space; // cell space
            }
            std::cout << left_wall << "\n"; // end wall
        }

        // bottom border walls
        for (int x = 0; x < numCols; x++) {
            auto walls = maze.getCellWalls(x, numRows - 1);
            std::cout << corner << (walls[2] ? top_wall : cell_space);
        }
        std::cout << corner << "\n"; // last corner
    }
}
