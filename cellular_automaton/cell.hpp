#pragma once

#include <SFML/Graphics.hpp>

enum State {
	DEAD = 0,
	ALIVE = 1
};

class Cell {
public:
	Cell();
	State getState();
	void setState(State);
private:
	State state;
	//sf::Color color;
};