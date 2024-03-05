#include "matrix.hpp"
#include "cell.hpp"
#include "rule_set.hpp"
#include <exception>
#include <vector>

// Should initialise a matrix of variable width and height 
// with default (dead) cells
Matrix::Matrix(int cell_size_, int window_w_, int window_h_) {
	width = window_w_ / cell_size_;
	height = window_h_ / cell_size_;
	int grid_size_ = width * height;

	Cell cell;
	matrix->assign(grid_size_, cell);

}

Cell Matrix::getCellAtIndex(int x, int y) {
	return matrix->at(x + y * width);
}

std::vector<Cell> Matrix::getCellNeigbors4(int x, int y) {
	std::vector<Cell> neighbors_;
	Cell cell_;

	cell_ = getCellAtIndex(x, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x, y + 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 1, y);
	neighbors_.push_back(cell_);

	return neighbors_;
}

std::vector<Cell> Matrix::getCellNeigbors8(int x, int y) {
	std::vector<Cell> neighbors_;
	Cell cell_;

	cell_ = getCellAtIndex(x, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x, y + 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 1, y);
	neighbors_.push_back(cell_);

	cell_ = getCellAtIndex(x + 1, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 1, y + 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y + 1);
	neighbors_.push_back(cell_);

	return neighbors_;
}

std::vector<Cell> Matrix::getCellNeigbors24(int x, int y) {
	std::vector<Cell> neighbors_;
	Cell cell_;

	cell_ = getCellAtIndex(x, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x, y + 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 1, y);
	neighbors_.push_back(cell_);

	cell_ = getCellAtIndex(x + 1, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 1, y + 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y + 1);
	neighbors_.push_back(cell_);

	cell_ = getCellAtIndex(x, y - 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y - 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 2, y - 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 1, y - 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 2, y - 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x, y - 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 1, y +2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 2, y + 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 1, y + 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 2, y + 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 2, y);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 2, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 2, y - 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 2, y + 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x - 2, y + 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 2, y);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 2, y - 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 2, y - 2);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 2, y + 1);
	neighbors_.push_back(cell_);
	cell_ = getCellAtIndex(x + 2, y + 2);
	neighbors_.push_back(cell_);

	return neighbors_;
}

void Matrix::setCellAtIndex(int x, int y, Cell cell_) {
	matrix->at(x + y * width) = cell_;
}

void Matrix::updateCellAtIndex(int x, int y) {

}

void Matrix::setCellAtIndex(int index_, Cell cell_) {
	matrix->at(index_) = cell_;
}

void Matrix::updateCellAtIndex(int index_) {

}