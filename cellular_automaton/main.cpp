#include "main.hpp"
#include "display.hpp"

// Use modules

int main() {
    Display display;

    while (display.running()) {
        display.update();
    }

    return 0;
}