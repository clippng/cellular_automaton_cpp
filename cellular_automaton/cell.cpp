#include "cell.hpp"

Cell::Cell(const State state, const float width, const float height, const float pos_x, const float pos_y, const sf::Color colour, const sf::Color outline_colour, const float outline_thickness) {
	this->state = state;
	this->colour = colour;

	shape.setSize( { width, height } );
	shape.setPosition(pos_x, pos_y);
	shape.setFillColor(colour);
	shape.setOutlineColor(outline_colour);
	shape.setOutlineThickness(outline_thickness);
}

State Cell::getState() {
	return state;
}

void Cell::setState(State state) {
	this->state = state;
}

void Cell::updateColour(sf::Color colour) {
	this->colour = colour;
}