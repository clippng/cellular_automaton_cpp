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
	simulation = std::unique_ptr<Simulation>(new Simulation(WINDOW_WIDTH / PIXEL_MODIFIER, WINDOW_HEIGHT / PIXEL_MODIFIER, 1));
    matrix = simulation->getMatrixPointer();
}

void Display::initialiseWindow() {
    video_mode.height = WINDOW_HEIGHT;
    video_mode.width = WINDOW_WIDTH;
    window = new sf::RenderWindow(sf::RenderWindow(video_mode, "Sand_sim", sf::Style::Titlebar | sf::Style::Close));
    window->setFramerateLimit(1);
}

void Display::update() {
    simulation->nextGeneration();
    //updateMousePosition();

    pollEvents();
    window->clear();
    for (uint32_t i = 0; i < matrix->getColumns(); ++i) {
        for (uint32_t j = 0; j < matrix->getRows(); ++j) {
           window->draw(*matrix->getCell(i, j)->getDrawable());
        }
    }
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
