#include "rule_set.hpp"
#include "cell.hpp"

// GameOfLife::GameOfLife() {

// }

// GameOfLife::~GameOfLife() {
	
// }


State GameOfLife::updateCell(State current_state, unsigned int neighbours) {
	switch (current_state) {
		case ALIVE:
			if (neighbours < 2) {
				return DEAD;
			} else if (neighbours == 2 || neighbours == 3) {
				return ALIVE;
			} return DEAD;
		case DEAD:
			if (neighbours == 3) {
				return ALIVE;
			} return DEAD;
		default:
			return UNKOWN_STATE;
	}		
}