#pragma once

#include "cell.hpp"

enum Condition {
	EQUAL_TO = 0,
	LESS_THAN = 1,
	GREATER_THAN = 2
};

class Rule {
public:
	Rule(State initial_state_, Condition condition_, int condition_value_, State final_state_);
	State checkCell(State state_, int neighbors);
private:
	State initial_state; // only checks cells that match this state
	Condition condition; // holds the operator to compare values
	int condition_value;
	State conditional_state; // if condition is true changes state to match
};
