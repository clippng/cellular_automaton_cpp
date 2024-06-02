#include "matrix.hpp"
#include "cell.hpp"
#include "display.hpp"

#include <iostream>

// ive fixed this class 

Matrix::Matrix(const uint32_t columns, const uint32_t rows) {
	data = std::shared_ptr<std::vector<std::vector<Cell*>>>(new std::vector<std::vector<Cell*>>());
	*data = *new std::vector<std::vector<Cell*>>(columns);
	this->rows = rows;
	this->columns = columns;
	this->size = this->rows * this->columns;

	for (uint32_t i = 0; i < this->columns; ++i) {
		for (uint32_t j = 0; j < this->rows; ++j) {
			Cell *cell = new Cell(DEAD, PIXEL_MODIFIER, PIXEL_MODIFIER, i * PIXEL_MODIFIER, j * PIXEL_MODIFIER, sf::Color::Black, sf::Color::White, 0.0f);
			data->at(i).push_back(cell);
			data->at(i).at(j)->updateColour();
		}
	}

	data->at(columns/ 2).at(rows /2)->setState(ALIVE);
	data->at(columns/ 2).at(rows /2 -1)->setState(ALIVE);
	data->at(columns/ 2-1).at(rows /2)->setState(ALIVE);
	data->at(columns/ 2).at(rows /2+1)->setState(ALIVE);
	data->at(columns/ 2 + 1).at(rows /2 + 1)->setState(ALIVE);
}

Matrix::~Matrix() {
	for (int i = 0; i < columns; ++i) {
		for (int j = 0; j < rows; ++j) {
			delete data->at(i).at(j);
		}
	}
}

uint32_t Matrix::getRows() { return rows; } 

uint32_t Matrix::getColumns() { return columns; }

uint32_t Matrix::getSize() const { return size; }

std::shared_ptr<std::vector<std::vector<Cell*>>> Matrix::getReference() {
	return data;
}

void Matrix::update() {
	// cpy prev gen into next gen operate on prev gen and save to next gen -- push next gen into data and repeat
	next_generation_data = data;

	emptyMatrix(data.get());

	for (uint32_t i = 0; i < columns; ++i) {
		for (uint32_t j = 0; j < rows; ++j) {
			Cell* cell = new Cell(next_generation_data->at(i).at(j)->getState(), PIXEL_MODIFIER, PIXEL_MODIFIER, i * PIXEL_MODIFIER, j * PIXEL_MODIFIER, sf::Color::Black, sf::Color::White, 0.0f);
			data->at(i).push_back(cell);
			data->at(i).at(j)->updateColour();
		}
	}
}

void Matrix::updateCell(uint32_t column, uint32_t row) {
	const uint32_t MAX_COLUMN = data->size() - 1;
	const uint32_t MAX_ROW = data->front().size() - 1;

	if (column == 0) {
		column = MAX_COLUMN;
	} else if (column > MAX_COLUMN) {
		column = 0;
	} 
	
	if (row == 0) {
		row = MAX_ROW;
	} else if (row > MAX_ROW) {
		row = 0;
	}

	data->at(column).at(row)->Cell::updateCell(getCellNeighbours(column, row, MAX_COLUMN, MAX_ROW));

	data->at(column).at(row)->updateColour();
}

uint32_t Matrix::getCellNeighbours(const uint32_t column, const uint32_t row, const uint32_t MAX_COLUMN, const uint32_t MAX_ROW) {
	uint32_t alive_neighbours = 0;
	uint32_t column_left = 0, column_right = 0, row_up = 0, row_down = 0;

	if (column + 1 > MAX_COLUMN) {
		column_right = 0;
	} else {
		column_right = column + 1;		
	} if (column == 0) {
		column_left = MAX_COLUMN;
	} else {
		column_left = column - 1;
	}
	
	if (row + 1 > MAX_ROW) {
		row_up = 0;
	} else {
		row_up = row + 1;		
	} if (row == 0) {
		row_down = MAX_ROW;
	} else {
		row_down = row - 1;
	}

	if (data->at(column_right).at(row_up)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data->at(column_right).at(row)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data->at(column_right).at(row_down)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data->at(column).at(row_up)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data->at(column).at(row_down)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data->at(column_left).at(row_up)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data->at(column_left).at(row)->getState() == ALIVE) {
		alive_neighbours++;
	} if (data->at(column_left).at(row_down)->getState() == ALIVE) {
		alive_neighbours++;
	}
	return alive_neighbours;
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

// deletes all cells owned by a matrix
void Matrix::emptyMatrix(const std::vector<std::vector<Cell*>>* pointer) {

}
