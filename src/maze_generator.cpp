#include "maze_generator.hpp"
#include <csignal>
#include <random>
#include <stack>
#include <stdexcept>

// ----------------- MazeGenerator -----------------
MazeGenerator::MazeGenerator(std::string algo_name) : name(algo_name) {}

// ----------------- RDFSIterativeGenerator -----------------
RDFSIterativeGenerator::RDFSIterativeGenerator() : MazeGenerator("RDFS") {
    // random seed
    this->engine.seed(std::random_device{}());
}

RDFSIterativeGenerator::RDFSIterativeGenerator(std::mt19937::result_type seed) : MazeGenerator("RDFS") {
    this->engine.seed(seed);
}

unsigned int RDFSIterativeGenerator::uniform_random_generator(int min, int max) {
    // validate args
    if ((min > max) || (min < 0) || (max < 0)) {
        throw std::invalid_argument("Invalid arguments for uniform_random_generator: min must be <= max and both must be non-negative");
    }
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
    return dist(engine);
}

void RDFSIterativeGenerator::generate(Maze& maze) {
    int numRows = maze.getHeight();
    int numCols = maze.getWidth();
    // pick a cell randomly
    int x = uniform_random_generator(0, numCols - 1);
    int y = uniform_random_generator(0, numRows - 1);
    std::pair<int, int> cc{x,y};
    // mark visited and add to stack
    maze.setCellStatus(x, y, true);
    std::stack<std::pair<int, int>> cellStack;
    cellStack.push(cc);
    // neighbour storage
    std::stack<std::pair<int, int>> neighbours;
    std::pair<int, int> neighbour;
    // while stack is not empty
    while (!cellStack.empty()) {
        // get current cell from stack
        cc = cellStack.top();
        cellStack.pop();
        // get all neighbours
        neighbours = maze.getAdjacentNeighbours(cc.first, cc.second);
        while (!neighbours.empty()) {
            neighbour = neighbours.top();
            // check if visited
            if (!maze.getCellStatus(neighbour.first, neighbour.second)) {
                break;
            } else {
                neighbours.pop();
            }
        }
        // if cell has unvisited neighbours
        if (!neighbours.empty()) {
            // add current cell to stack
            cellStack.push(cc);
            // pick an unvisited neighbour randomly
            neighbour = neighbours.top();
            // remove wall between cell and neighbour
            maze.removeWall(cc.first, cc.second, neighbour.first, neighbour.second);
            // mark neighbour visited and add to stack
            maze.setCellStatus(neighbour.first, neighbour.second, true);
            cellStack.push(neighbour);
        }
    }
}
