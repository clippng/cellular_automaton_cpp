#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
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

    const bool running();

    void updateMousePosition();
    void pollEvents();

    void update();
    void updateTexture();
    void render();
	sf::CircleShape shape;
    
private:
	unsigned int window_width = 1280;
    unsigned int window_height = 800;
    int pixelModifer = 2;

	std::unique_ptr<sf::RenderWindow> window;
	sf::Vector2u window_size{ 1280, 800 };
    sf::Event event;
    sf::VideoMode video_mode;
    sf::Vector2i mouse_position_in_window;

    std::unique_ptr<sf::Sprite> sprite;
    std::unique_ptr<sf::Texture> texture;

	std::unique_ptr<UnitUtilities> unit_utilities;
	std::unique_ptr<Simulation> simulation;

    void initialiseVariables();
    void initialiseWindow();
};