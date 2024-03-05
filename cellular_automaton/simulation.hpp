#pragma once

#include <memory>

#include "matrix.hpp"
#include "unit_utilities.hpp"

class Simulation {
public:
    Simulation();
    void nextGeneration();

private:
    unsigned int width, height, size;
    unsigned int update_frequency;
    unsigned int generation;

    std::unique_ptr<Matrix> matrix;
    std::unique_ptr<UnitUtilities> unit_utilities;
    void initialiseVariables();

};