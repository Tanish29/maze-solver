#include "maze_generator.hpp"
#include <random>
#include <stack>

// MazeGenerator
MazeGenerator::MazeGenerator(std::string algo_name) : name(algo_name) {}

// RDFSGenerator
RDFSIterativeGenerator::RDFSIterativeGenerator(std::string algo_name) : MazeGenerator(algo_name) {}

void RDFSIterativeGenerator::generate(Maze& maze) {
    int numRows = maze.getHeight();
    int numCols = maze.getWidth();
    // pick a cell randomly
    std::default_random_engine generator;
    std::uniform_int_distribution<int> rowDist(0, numRows);
    std::uniform_int_distribution<int> colDist(0, numCols);
    int x = rowDist(generator);
    int y = colDist(generator);
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
        // get neighbours
        neighbours = maze.getCellNeighbours(cc.first, cc.second);
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
