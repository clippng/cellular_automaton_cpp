#pragma once 

#include <vector>
#include <memory>

#include "rule.hpp"

class RuleSet {
public:
	RuleSet();
	void clearRuleSet();
	void addRule(Rule rule_);

	void gameOfLife();
	// neighbors to check == 8
	// if alive && alive neighbors < 2 = death
	// if alive && neighbors == 2 || 3 = live
	// if alive && neigbors > 3 = death
	// if dead and neighbors == 3 = live

private:
	std::unique_ptr<std::vector<Rule>> rules;

};