#include "display.hpp"
#include "simulation.hpp"
#include <memory>


Display::Display() {
	initialiseVariables();
	initialiseWindow();
}

const bool Display::running() {
    return window->isOpen();
}

void Display::initialiseVariables() {
    unit_utilities = std::unique_ptr<UnitUtilities>(new UnitUtilities(pixelModifer, window_width, window_height));
	simulation = std::unique_ptr<Simulation>(new Simulation());
}

void Display::initialiseWindow() {
    video_mode.height = window_height;
    video_mode.width = window_width;
    window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(video_mode, "Sand_sim",
        sf::Style::Titlebar | sf::Style::Close));
    window->setFramerateLimit(144);

    shape.setRadius(200.0f);
    
    shape.setFillColor(sf::Color::Red);
}

void Display::update() {
    //updateMousePosition();
    pollEvents();
	//simulation->nextGeneration();
    window->clear();
    window->draw(shape);
    window->display();
}

void Display::updateTexture() {

}

void Display::render() {

}

void Display::updateMousePosition() {
    mouse_position_in_window = sf::Mouse::getPosition(*window);
}

void Display::pollEvents() {
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}
