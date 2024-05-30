#include "matrix.hpp"
#include "cell.hpp"

// ive fixed this class --apart from the destructor

Matrix::Matrix(const uint32_t rows, const uint32_t columns) {
	matrix.resize(rows);

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < columns; ++j) {
			Cell *cell = new Cell;
			matrix[i].push_back(cell);
		}
	}

}

Matrix::~Matrix() {
	// const int rows = matrix.size();
	// const int columns = matrix[0].size();
	// for (int i = 0; i < rows; ++i) {
	// 	for (int j = 0; j < columns; ++j) {
	// 		delete &matrix[i].at(j);
	// 	}
	// }
}

State Matrix::getCellAtIndex(const uint32_t row, const uint32_t column) {
	return matrix[row].at(column)->getState();
}

void Matrix::setCellAtIndex(const uint32_t row, const uint32_t column, const State state) {
	matrix[row].at(column)->setState(state);
}
