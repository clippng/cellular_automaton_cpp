#pragma once

#include <SFML/Graphics.hpp>

enum State {
	DEAD = 0,
	ALIVE = 1,
	UNKOWN_STATE = 666
};

class Cell {
public:
	Cell(const State state, const float width, const float height, const float pos_x, const float pos_y, const sf::Color colour, const sf::Color outline_colour, const float outline_thickness);
	
	~Cell();

	void updateCell(uint32_t alive_neighbours);

	State getState();

	void setState(State state);

	void updateColour();

	sf::RectangleShape* getDrawable();

private:
	State state;
	sf::Color colour;
	sf::RectangleShape shape;
};