#pragma once

#include <vector>
#include <memory>

#include "cell.hpp"

// needs to be reinitialised if size changes

class Matrix {
public:
	Matrix(const uint32_t rows, const uint32_t columns);

	~Matrix();

	uint32_t getRows();

	uint32_t getColumns();

	uint32_t getSize();

	std::shared_ptr<std::vector<std::vector<Cell*>>> getReference();

	State getCellState(const uint32_t row, const uint32_t column);

	Cell* getCell(const uint32_t row, const uint32_t column);

	void setCell(const uint32_t row, const uint32_t column, const State state);


private:
	std::shared_ptr<std::vector<std::vector<Cell*>>> data;
	uint32_t rows, columns, size;
};