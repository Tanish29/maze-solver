#include "maze.hpp"
#include <iostream>
#include "maze_generator.hpp"
#include "maze_visualiser.hpp"

int main() {
    // get maze dimensions from user
    int width, height;
    std::cout << "Enter maze width: ";
    std::cin >> width;
    std::cout << "Enter maze height: ";
    std::cin >> height;

    // Validate input
    if (width <= 0 || height <= 0) {
        std::cout << "Invalid dimensions!\n";
        return 1;
    }

    // create a maze object
    Maze maze(width, height);

    // generate a maze
    RDFSIterativeGenerator generator;
    generator.generate(maze);

    // visualise generate maze
    std::cout << "\nGenerated Maze:\n";
    MazeVisualiser::printMaze(maze);

    return 0;
}
