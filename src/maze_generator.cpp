#include "maze_generator.hpp"

MazeGenerator::MazeGenerator(std::string algo_name) : name(algo_name) {}

RDFSGenerator::RDFSGenerator(std::string algo_name) : MazeGenerator(algo_name) {}

void RDFSGenerator::generate(Maze& maze) {}
