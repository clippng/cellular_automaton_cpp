#include <memory>

#include "simulation.hpp"
#include "matrix.hpp"
#include "unit_utilities.hpp"


Simulation::Simulation() {
    initialiseVariables();
}

void Simulation::nextGeneration() {
    for (int i = 0; i < size; ++i) {
        matrix->updateCellAtIndex(i);
    }
}

void Simulation::initialiseVariables() {
    matrix = std::unique_ptr<Matrix>(new Matrix(4, 1280, 800));
}




