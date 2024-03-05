#include "cell.hpp"

Cell::Cell() {
	state = DEAD;
}

State Cell::getState() {
	return state;
}

void Cell::setState(State state_) {
	state = state_;
}