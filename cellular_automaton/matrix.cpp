#include "matrix.hpp"
#include "cell.hpp"

#include <error.h>
#include <iostream>

Matrix::Matrix(const std::shared_ptr<UnitUtilities> unit_utilities) {
	this->unit_utilities = unit_utilities;
	rows = unit_utilities->getMatrixHeight();
	columns = unit_utilities->getMatrixHeight();

	data = std::vector<std::vector<Cell*>>();

	for (uint32_t i = 0; i < rows; ++i) {
		std::vector<Cell*> vector = std::vector<Cell*>();
		data.push_back(vector);
		for (uint32_t j = 0; j < columns; ++j) {
			State state = DEAD;
			// if (i % 2 == 0 || j % 3 == 0) {
			// 	state = ALIVE;
			// }
			Cell* cell = new Cell(state, unit_utilities->getUnitSize(), unit_utilities->getUnitSize(), unit_utilities->convertToScreen(i), 
						unit_utilities->convertToScreen(j), sf::Color::White, sf::Color::White, 0.0f);
			data.at(i).push_back(cell);
			data.at(i).at(j)->updateColour();
		}
	}

	data.at(columns/ 2).at(rows /2)->setState(ALIVE);
	data.at(columns/ 2).at(rows /2 -1)->setState(ALIVE);
	data.at(columns/ 2-1).at(rows /2)->setState(ALIVE);
	data.at(columns/ 2).at(rows /2+1)->setState(ALIVE);
	data.at(columns/ 2 + 1).at(rows /2 + 1)->setState(ALIVE);

	if (rows < 1 || columns < 1) { 
		throw std::runtime_error("fucked");
		exit(10);
	}
}

Matrix::~Matrix() {

}

uint32_t Matrix::getCellNeighbours(const uint32_t row, const uint32_t column, const uint32_t MAX_ROW, const uint32_t MAX_COLUMN) {
	uint32_t alive_neighbours = 0;
	uint32_t column_left = 0, column_right = 0, row_up = 0, row_down = 0;

	if (row + 1 > MAX_ROW) {
		column_right = 0;
	} else {
		column_right = row + 1;		
	} if (row == 0) {
		column_left = MAX_ROW;
	} else {
		column_left = row - 1;
	}
	
	if (column + 1 > MAX_COLUMN) {
		row_up = 0;
	} else {
		row_up = column + 1;		
	} if (column == 0) {
		row_down = MAX_COLUMN;
	} else {
		row_down = column - 1;
	}

	if (data.at(column_right).at(row_up)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data.at(column_right).at(column)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data.at(column_right).at(row_down)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data.at(row).at(row_up)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data.at(row).at(row_down)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data.at(column_left).at(row_up)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data.at(column_left).at(column)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data.at(column_left).at(row_down)->getState() == ALIVE) {
		alive_neighbours++;
	}
	return alive_neighbours;
}

State Matrix::getCellState(const uint32_t row, const uint32_t column) {
	return data.at(row).at(column)->getState();
}

Cell* Matrix::getCell(const uint32_t row, const uint32_t column) {
	return data.at(row).at(column);
}

void Matrix::setCell(const uint32_t row, const uint32_t column, const State state) {
	data.at(row).at(column)->setState(state);
}

void Matrix::copyMatrixData(Matrix* matrix_data) {
	if (matrix_data->rows != rows || matrix_data->columns != columns) {
		throw std::runtime_error("Error: Matrices are inconpatible");
	}

	for (uint32_t row = 0; row < matrix_data->rows; row++) {
		for (uint32_t column = 0; column < matrix_data->columns; column++) {
			data.at(row).at(column)->setState(matrix_data->getCellState(row, column));
		}
	}
}

void Matrix::emptyMatrixData() {
	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j  = 0; j < columns; j++) {
			delete data.at(i).at(j);
		}
	}

	if (!data.empty()) {
		throw std::runtime_error("Error: Couldn't empty matrix");
	}
}
