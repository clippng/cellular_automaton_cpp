#pragma once

#include <vector>
#include <memory>

#include "cell.hpp"
#include "rule_set.hpp"

class Matrix {
public:
	Matrix(int cell_size_, int window_w_, int window_h_);

	Cell getCellAtIndex(int x, int y);
	std::vector<Cell> getCellNeigbors4(int x, int y);
	std::vector<Cell> getCellNeigbors8(int x, int y);
	std::vector<Cell> getCellNeigbors24(int x, int y);
	//std::vector<Cell> getCellNeigbors48(int x, int y);

	void setCellAtIndex(int x, int y, Cell cell_); // explicitly set a cell
	void setCellAtIndex(int index_, Cell cell_);
	void updateCellAtIndex(int x, int y); // implicitly update based off rule set
	void updateCellAtIndex(int index_);

//private:
	unsigned int width;
	unsigned int height;
	unsigned int cell_size; // w / h of each cell

	std::unique_ptr<std::vector<Cell>> matrix;
	std::unique_ptr<GameOfLife> rule_set;
};