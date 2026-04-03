#pragma once
#include "maze.hpp"
#include <string>
#include <random>

class MazeGenerator {
    public:
        MazeGenerator(std::string algo_name);
    protected:
        virtual void generate(Maze& maze) = 0;
    protected:
        std::string name;
};

// material: https://en.wikipedia.org/wiki/Maze_generation_algorithm
class RDFSIterativeGenerator : public MazeGenerator {
    public:
        RDFSIterativeGenerator();
        // seed overload
        RDFSIterativeGenerator(std::mt19937::result_type seed);
        void generate(Maze& maze) override;

    private:
        unsigned int uniform_random_generator(int min, int max);
        std::mt19937 engine;
};
