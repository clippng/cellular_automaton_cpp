#include "simulation.hpp"

#include <iostream>

Simulation::Simulation(const uint32_t columns, const uint32_t rows, const uint32_t update_frequency, const std::shared_ptr<UnitUtilities> unit_utilities) {
    this->rows = rows;
    this->columns = columns;
    this->update_frequency = update_frequency;
    this->unit_utilities = unit_utilities;

    generation = 0;

    matrix = std::shared_ptr<Matrix>(new Matrix(rows, columns, unit_utilities));
}

Simulation::~Simulation() {

}

void Simulation::nextGeneration() {
    matrix->update();
    // for (uint32_t i = 0; i < matrix->getColumns(); ++i) { 
    //     for (uint32_t j = 0; j < matrix->getRows(); ++j) {
    //         matrix->updateCell(i, j);
    //     }
    // }
}

std::shared_ptr<Matrix> Simulation::getMatrixPointer(){
    return matrix;
}





