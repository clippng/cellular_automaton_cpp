#pragma once

#include <vector>
#include <memory>

#include "cell.hpp"

// needs to be reinitialised if size changes

class Matrix {
public:
	Matrix(const uint32_t rows, const uint32_t columns);

	~Matrix();

	State getCellAtIndex(const uint32_t row, const uint32_t column);

	void setCellAtIndex(const uint32_t row, const uint32_t column, const State state);

private:
	std::vector<std::vector<Cell*>> matrix;
};