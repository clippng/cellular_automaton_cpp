#pragma once

#include <cstdint>

// Tools for converting to / from window space to matrix space
class UnitUtilities {
public:
    UnitUtilities(uint32_t pixel_modifier, uint32_t window_width, uint32_t window_height);

	inline uint32_t convertToMatrix(uint32_t pixel_value) { return pixel_value / unit_size; }

	inline uint32_t convertToScreen(uint32_t matrix_value) { return matrix_value * unit_size; }

	inline uint32_t getWidth() { return window_width; }

	inline uint32_t getHeight() { return window_height; }

	inline uint32_t getMatrixHeight() { return matrix_height; }

	inline uint32_t getMatrixWidth() { return matrix_width; }

	inline uint32_t getUnitSize() { return unit_size; }
	
private:
	uint32_t window_width;
	uint32_t window_height;
	uint32_t matrix_height;
	uint32_t matrix_width;
	uint32_t unit_size;
};
