#pragma once

// Tools for converting to / from window space to matrix space
class UnitUtilities {
public:
    UnitUtilities(int _pixelModifier, int _windowWidth, int _windowHeight);

	int convertToMatrix(int pixelValue);
	int convertToPixel(int matrixValue);
	int getWidth();
	int getHeight();
	int getPixelModifier();
	int getMatrixHeight();
	int getMatrixWidth();
	int getPixelSize();
	int getQuadSize();
	
private:
	int pixelModifier;
	int windowWidth;
	int windowHeight;
	int matrixHeight;
	int matrixWidth;
	int quadSize;
	int pixelSize;
};
