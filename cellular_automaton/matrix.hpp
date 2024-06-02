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

	uint32_t getSize() const;

	std::shared_ptr<std::vector<std::vector<Cell*>>> getReference();

	void update();

	void updateCell(uint32_t column, uint32_t row);

	uint32_t getCellNeighbours(const uint32_t column, const uint32_t row, const uint32_t MAX_COLUMN, const uint32_t MAX_ROW);

	State getCellState(const uint32_t row, const uint32_t column);

	Cell* getCell(const uint32_t row, const uint32_t column);

	void setCell(const uint32_t row, const uint32_t column, const State state);

	void emptyMatrix(const std::vector<std::vector<Cell*>>* pointer);

private:
	std::shared_ptr<std::vector<std::vector<Cell*>>> data;
	std::shared_ptr<std::vector<std::vector<Cell*>>> next_generation_data;
	uint32_t rows, columns, size;
};