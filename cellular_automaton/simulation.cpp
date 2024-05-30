#include "simulation.hpp"

Simulation::Simulation(const uint32_t rows, const uint32_t columns, const uint32_t update_frequency) {
    this->rows = rows;
    this->columns = columns;
    this->update_frequency = update_frequency;
    generation = 0;
    matrix = std::shared_ptr<Matrix>(new Matrix(rows, columns));
}

Simulation::~Simulation() {

}

void Simulation::nextGeneration() {
    // logic
}





