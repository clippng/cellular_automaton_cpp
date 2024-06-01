#include "display.hpp"
#include "simulation.hpp"
#include <memory>

#include <iostream>

Display::Display() {
	initialiseVariables();
    std::cout << "Display init" << std::endl;
	initialiseWindow();
}

Display::~Display() { }

const bool Display::running() {
    return window->isOpen();
}

void Display::initialiseVariables() {
    //unit_utilities = std::unique_ptr<UnitUtilities>(new UnitUtilities(pixelModifer, window_width, window_height));
	std::unique_ptr<Simulation> simulation(new Simulation(window_width / pixelModifer, window_height / pixelModifer, 1));
    matrix = simulation->getMatrixPointer();
}

void Display::initialiseWindow() {
    video_mode.height = window_height;
    video_mode.width = window_width;
    window = new sf::RenderWindow(sf::RenderWindow(video_mode, "Sand_sim", sf::Style::Titlebar | sf::Style::Close));
    window->setFramerateLimit(144);

    shape.setRadius(200.0f);
    
    shape.setFillColor(sf::Color::Red);
}

void Display::update() {
    //updateMousePosition();
    pollEvents();
    window->clear();
    // draw cells in matrix (cell.shape)
    // std::shared_ptr<std::vector<std::vector<Cell*>>> cells = matrix->getReference();
    // for (uint32_t i = 0; i < matrix->getColumns(); ++i) {
    //     for (uint32_t j = 0; j < matrix->getRows(); ++i) {
    //         //window->draw(*cells->at(i).at(j)->getDrawable());
    //     }
    // }
    window->draw(shape);
    window->display();
}

void Display::render() {

}

void Display::updateMousePosition() {
    mouse_position_in_window = sf::Mouse::getPosition(*window);
}

void Display::pollEvents() {
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
            window->close();            
        }
    }
}
