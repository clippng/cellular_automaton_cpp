#pragma once

enum State {
	DEAD = 0,
	ALIVE = 1,
	UNKOWN_STATE = 666
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