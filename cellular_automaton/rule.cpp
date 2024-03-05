#include "rule.hpp"


Rule::Rule(State initial_state_, Condition condition_, int condition_value_, State conditional_state_) {
	initial_state = initial_state_;
	condition = condition_;
	condition_value = condition_value_;
	conditional_state = conditional_state_;
}

State Rule::checkCell(State state_, int neighbors_) {
	State return_state = state_;
	if (state_ == initial_state) {
		switch (condition) {
			case LESS_THAN:
				if (neighbors_ < condition_value) {
					return_state = conditional_state;
				}
				break;

			case GREATER_THAN:
				if (neighbors_ > condition_value) {
					return_state = conditional_state;
				}
				break;

			case EQUAL_TO: 
				if (neighbors_ == condition_value) {
					return_state = conditional_state;
				}
				break;
		}
	}
	return return_state;
}