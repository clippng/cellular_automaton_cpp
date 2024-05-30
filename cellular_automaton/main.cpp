#include "display.hpp"
#include "simulation.hpp"

#include <iostream>


int main() {
    Matrix display(10, 10);
	for (int i = 0; i < 10; ++i) {
        std::cout << "\n";
		for (int j = 0; j < 10; ++j) {
			std::cout << display.getCell(i, j);
		}
	}
    std::cout << std::endl;

    return 0;
}