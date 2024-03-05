#include "rule_set.hpp"
#include "cell.hpp"
#include "rule.hpp"

RuleSet::RuleSet() {
	gameOfLife();
}

void RuleSet::clearRuleSet() {
	rules->clear();
}

void RuleSet::addRule(Rule rule_) {
	rules->push_back(rule_);
}

void RuleSet::gameOfLife() {
	Rule rule_1(ALIVE, LESS_THAN, 2, DEAD);
	Rule rule_2(ALIVE, EQUAL_TO, 2, ALIVE);
	Rule rule_3(ALIVE, EQUAL_TO, 3, ALIVE);
	Rule rule_4(ALIVE, GREATER_THAN, 3, DEAD);
	Rule rule_5(DEAD, EQUAL_TO, 3, ALIVE);
	rules->push_back(rule_1);
	rules->push_back(rule_2);
	rules->push_back(rule_3);
	rules->push_back(rule_4);
	rules->push_back(rule_5);
}