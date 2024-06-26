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

Cell::~Cell() {

}

State Cell::getState() {
	return state;
}

void Cell::setState(State state) {
	this->state = state;
	updateColour();
}

void Cell::updateColour() {
	if (state == DEAD) {
		colour = sf::Color::Black;
	} else {
		colour = sf::Color::White;
	}
	shape.setFillColor(colour);
}

sf::RectangleShape* Cell::getDrawable() {
	return &shape;
}