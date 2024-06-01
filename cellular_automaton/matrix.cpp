#include "matrix.hpp"
#include "cell.hpp"

// ive fixed this class 

Matrix::Matrix(const uint32_t rows, const uint32_t columns) {
	data->resize(rows);
	this->rows = rows;
	this->columns = columns;
	this-> size = rows * columns;

	for (uint32_t i = 0; i < rows; ++i) {
		for (uint32_t j = 0; j < columns; ++j) {
			Cell *cell = new Cell(DEAD, 5, 5, i * 5, j * 5, sf::Color::Blue, sf::Color::Black, 0.5f);
			data->at(i).push_back(cell);
		}
	}

}

Matrix::~Matrix() {
	const int rows = data->size();
	const int columns = data->at(0).size();
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			delete data->at(i).at(j);
		}
	}
}

uint32_t Matrix::getRows() { return rows; }

uint32_t Matrix::getColumns() { return columns; }

uint32_t Matrix::getSize() { return size; }

std::shared_ptr<std::vector<std::vector<Cell*>>> Matrix::getReference() {
	return data;
}

State Matrix::getCellState(const uint32_t row, const uint32_t column) {
	return data->at(row).at(column)->getState();
}

Cell* Matrix::getCell(const uint32_t row, const uint32_t column) {
	return data->at(row).at(column);
}

void Matrix::setCell(const uint32_t row, const uint32_t column, const State state) {
	data->at(row).at(column)->setState(state);
}
