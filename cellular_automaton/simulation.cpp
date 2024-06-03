#include "simulation.hpp"
#include <iostream>

Simulation::Simulation(SIMULATION_INIT_INFO *init_info) {
    matrix_data.rows = init_info->rows;
    matrix_data.columns = init_info->columns;
    unit_utilities = init_info->unit_utilities;

    generation = 0;

    matrix_data.matrix_data = std::unique_ptr<Matrix>(new Matrix(unit_utilities));
    matrix_data.next_matrix_data = std::unique_ptr<Matrix>(new Matrix(unit_utilities));

    window_data.window_size = {unit_utilities->getWidth(), unit_utilities->getMatrixHeight()};
    window_data.video_mode.height = unit_utilities->getHeight();
    window_data.video_mode.width = unit_utilities->getWidth();
    window_data.window = new sf::RenderWindow(sf::RenderWindow(window_data.video_mode, 
        "Automaton_cpp", sf::Style::None));
    window_data.window->setFramerateLimit(window_data.MAX_FRAME_RATE);
}

Simulation::~Simulation() {

}

const bool Simulation::running() {
    return window_data.window->isOpen();
}

void Simulation::update() {
    window_data.updateMousePosition();
    nextGeneration();
    render();
}

void Simulation::nextGeneration() {
    matrix_data.update();
}

void Simulation::render() {
    window_data.pollEvents();
    window_data.window->clear();

    for (uint32_t row = 0; row < matrix_data.rows; ++row) {
        for (uint32_t column = 0; column < matrix_data.rows; ++column) {
           window_data.window->draw(*matrix_data.matrix_data->getCell(row, column)->getDrawable());
        }
    }

    window_data.window->display();
}

void Simulation::WINDOW_DATA::updateMousePosition() {
    mouse_position_in_window = sf::Mouse::getPosition(*window);
}

void Simulation::WINDOW_DATA::pollEvents() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
            window->close();            
        }
    }
}

void Simulation::MATRIX_DATA::update() {
    const uint32_t MAX_COLUMN = columns - 1;
    const uint32_t MAX_ROW = rows - 1;

    for (uint32_t row = 0; row < rows; ++row) { 
        for (uint32_t column = 0; column < columns; ++column) {
            uint32_t alive_neighbours = matrix_data->getCellNeighbours(row, column, MAX_ROW, MAX_COLUMN);
            State state = matrix_data->getCellState(row, column);

            if (state == ALIVE) {
                if (alive_neighbours < 2) {
                    state = DEAD;
                } else if (alive_neighbours < 4) {
                    state = ALIVE;
                } else {
                    state = DEAD;
                }
            } else {
                if (alive_neighbours == 3) {
                    state = ALIVE;
                }
            }

            next_matrix_data->setCell(row, column, state);
        }
    }

	matrix_data->copyMatrixData(next_matrix_data.get());
}



