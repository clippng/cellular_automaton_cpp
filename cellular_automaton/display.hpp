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
	sf::CircleShape shape;
    
private:
	uint32_t window_width = 1280;
    uint32_t window_height = 800;
    uint32_t pixelModifer = 2;
    static constexpr unsigned ticks_per_second = 60; 
    const sf::Time timePerUpdate = sf::seconds(1.0f / float(ticks_per_second));

	sf::RenderWindow* window;
	sf::Vector2u window_size{ 1280, 800 };
    sf::Event event;
    sf::VideoMode video_mode;
    sf::Vector2i mouse_position_in_window;

    std::shared_ptr<Matrix> matrix; // make this point to the matrix in simulation
	std::unique_ptr<UnitUtilities> unit_utilities;
	std::unique_ptr<Simulation> simulation;

    void initialiseVariables();
    void initialiseWindow();
};