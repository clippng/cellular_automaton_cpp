#include "simulation.hpp"

#include <iostream>

Simulation::Simulation(const uint32_t rows, const uint32_t columns, const uint32_t update_frequency) {
    this->rows = rows;
    this->columns = columns;
    this->update_frequency = update_frequency;

    generation = 0;

    // seg faults
    matrix = std::make_shared<Matrix>(rows, columns);
}

Simulation::~Simulation() {

}

void Simulation::nextGeneration() {
    // logic
}

std::shared_ptr<Matrix> Simulation::getMatrixPointer(){
    return matrix;
}





