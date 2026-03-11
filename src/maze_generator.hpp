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

class RDFSGenerator : public MazeGenerator {
    public:
        RDFSGenerator(std::string algo_name);
        void generate(Maze& maze) override;
};
