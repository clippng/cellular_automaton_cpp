#pragma once 

#include <vector>

#include "cell.hpp"

class RuleSet {
public:
	//virtual State updateCell(State current_state, std::vector<State> neighbors);
	virtual State updateCell(State current_state, unsigned int neighbours) = 0;
protected:

};

class GameOfLife: RuleSet {
public:
	//GameOfLife();
	//~GameOfLife();

	State updateCell(State current_state, unsigned int neighbours) override;

private:
	unsigned int neigbor_cells = 8;

};