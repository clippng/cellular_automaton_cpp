#pragma once

#include <vector>
#include <memory>

#include "cell.hpp"
#include "unit_utilities.hpp"

// needs to be reinitialised if size changes

class Matrix {
public:
	Matrix(const std::shared_ptr<UnitUtilities> unit_utilities);

	~Matrix();

	uint32_t getCellNeighbours(const uint32_t row, const uint32_t column, const uint32_t MAX_ROW, const uint32_t MAX_COLUMN);

	State getCellState(const uint32_t row, const uint32_t column);

	Cell* getCell(const uint32_t row, const uint32_t column);

	void setCell(const uint32_t row, const uint32_t column, const State state);

	void copyMatrixData(Matrix* matrix_data);

	void emptyMatrixData();

private:
	std::shared_ptr<UnitUtilities> unit_utilities;

	std::vector<std::vector<Cell*>> data;

	uint32_t rows, columns;

};