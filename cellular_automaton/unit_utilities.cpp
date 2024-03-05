#include "unit_utilities.hpp"

UnitUtilities::UnitUtilities(int _pixelModifier, int _windowWidth, int _windowHeight) {
	pixelModifier = _pixelModifier;
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
	matrixHeight = _windowHeight / _pixelModifier;
	matrixWidth = _windowWidth / _pixelModifier;
	quadSize = 4;
	pixelSize = 4;
}

int UnitUtilities::convertToMatrix(int pixelValue) {
    return pixelValue / pixelModifier;
}


int UnitUtilities::convertToPixel(int matrixValue)
{
	return matrixValue * pixelModifier;
}

int UnitUtilities::getWidth()
{
	return windowWidth;
}

int UnitUtilities::getHeight()
{
	return windowHeight;
}

int UnitUtilities::getPixelModifier()
{
	return pixelModifier;
}

int UnitUtilities::getMatrixHeight()
{
	return matrixHeight;
}

int UnitUtilities::getMatrixWidth()
{
	return matrixWidth;
}

int UnitUtilities::getPixelSize()
{
	return pixelSize;
}

int UnitUtilities::getQuadSize()
{
	return quadSize;
}