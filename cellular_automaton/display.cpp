#include "display.hpp"
#include "simulation.hpp"
#include <memory>


Display::Display() {
	initialiseVariables();
	initialiseWindow();
}

Display::~Display() { }

const bool Display::running() {
    return window->isOpen();
}

void Display::initialiseVariables() {
    unit_utilities = std::unique_ptr<UnitUtilities>(new UnitUtilities(pixelModifer, window_width, window_height));
	simulation = std::unique_ptr<Simulation>(new Simulation(window_width / pixelModifer, window_height / pixelModifer, 1));
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
