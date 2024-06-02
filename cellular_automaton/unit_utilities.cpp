#include "unit_utilities.hpp"

UnitUtilities::UnitUtilities(uint32_t unit_size, uint32_t window_width, uint32_t window_height) {
	this->unit_size = unit_size;
	this->window_width = window_width;
	this->window_height = window_height;
	matrix_height = window_height / unit_size;
	matrix_width = window_width / unit_size;

}

uint32_t UnitUtilities::convertToMatrix(uint32_t pixel_value) { return pixel_value / unit_size; }

uint32_t UnitUtilities::convertToPixel(uint32_t matrix_value) { return matrix_value * unit_size; }

uint32_t UnitUtilities::getWidth() { return window_width; }

uint32_t UnitUtilities::getHeight() { return window_height; }

uint32_t UnitUtilities::getMatrixHeight() { return matrix_height; }

uint32_t UnitUtilities::getMatrixWidth() { return matrix_width; }

uint32_t UnitUtilities::getPixelSize() { return unit_size; }

