#include "unit_utilities.hpp"

UnitUtilities::UnitUtilities(uint32_t unit_size, uint32_t window_width, uint32_t window_height) {
	this->unit_size = unit_size;
	this->window_width = window_width;
	this->window_height = window_height;
	matrix_height = window_height / unit_size;
	matrix_width = window_width / unit_size;
}

