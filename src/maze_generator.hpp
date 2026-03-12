#pragma once
#include "maze.hpp"
#include <string>

class MazeGenerator {
    public:
        MazeGenerator(std::string algo_name);
        virtual void generate(Maze& maze) = 0;
    protected:
        std::string name;
};

// material: https://en.wikipedia.org/wiki/Maze_generation_algorithm
class RDFSIterativeGenerator : public MazeGenerator {
    public:
        RDFSIterativeGenerator(std::string algo_name);
        void generate(Maze& maze) override;
};
