#include "display.hpp"

#include <iostream>

// works but the architecture is disgusting

int main() {
    Display display;

    while (display.running()) {
        display.update();
    }

    std::cout << "Exit success" << std::endl;

    return 0;
}