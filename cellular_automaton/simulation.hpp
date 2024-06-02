#pragma once

#include <memory>

#include "matrix.hpp"
#include "unit_utilities.hpp"

class Simulation {
public:
    Simulation(const uint32_t columns, const uint32_t rows, const uint32_t update_frequency, const std::shared_ptr<UnitUtilities> unit_utilities);
    ~Simulation();
    void nextGeneration();
    std::shared_ptr<Matrix> getMatrixPointer();

private:
    uint32_t rows, columns;
    uint32_t update_frequency;
    uint32_t generation;

    std::shared_ptr<Matrix> matrix;
    std::shared_ptr<UnitUtilities> unit_utilities;

};