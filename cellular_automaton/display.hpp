#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "simulation.hpp"
#include "unit_utilities.hpp"
// Display class - handles all sfml rendering, simulation class
// is for the actual logic 

class Display {
public:
	Display();
    ~Display();

    const bool running();

    void updateMousePosition();
    void pollEvents();

    void update();
    void render();
    
private:
    static constexpr unsigned ticks_per_second = 60; 
    const sf::Time timePerUpdate = sf::seconds(1.0f / float(ticks_per_second));

    const uint32_t WINDOW_WIDTH = 800;
    const uint32_t WINDOW_HEIGHT = 800;
    const uint32_t PIXEL_MODIFIER = 5;
    const uint32_t MAX_FRAME_RATE = 144;

    sf::RenderWindow *window;
    sf::Vector2u window_size{1280, 800};
    sf::Event event;
    sf::VideoMode video_mode;
    sf::Vector2i mouse_position_in_window;

    std::shared_ptr<Matrix> matrix; // make this point to the matrix in simulation
	std::shared_ptr<UnitUtilities> unit_utilities;
	std::unique_ptr<Simulation> simulation;

    void initialiseVariables();
    void initialiseWindow();
};