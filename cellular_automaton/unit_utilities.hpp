#pragma once

#include <cstdint>

// Tools for converting to / from window space to matrix space
class UnitUtilities {
public:
    UnitUtilities(uint32_t pixel_modifier, uint32_t window_width, uint32_t window_height);

	uint32_t convertToMatrix(uint32_t pixel_value);

	uint32_t convertToPixel(uint32_t matrix_value);

	uint32_t getWidth();

	uint32_t getHeight();

	uint32_t getMatrixHeight();

	uint32_t getMatrixWidth();
	
	uint32_t getPixelSize();
	
private:
	uint32_t window_width;
	uint32_t window_height;
	uint32_t matrix_height;
	uint32_t matrix_width;
	uint32_t unit_size;
};
