#include "simulation.hpp"
#include "unit_utilities.hpp"

#include <iostream>

// works but the architecture is disgusting

int main() {
    const uint32_t PIXEL_SIZE = 5;
    const uint32_t WINDOW_WIDTH = 800;
    const uint32_t WINDOW_HEIGHT = 800;

    std::shared_ptr<UnitUtilities> unit_utilities(new UnitUtilities(PIXEL_SIZE, WINDOW_WIDTH, WINDOW_HEIGHT));

    SIMULATION_INIT_INFO init_info{};
    init_info.columns = unit_utilities->getMatrixWidth();
    init_info.rows = unit_utilities->getMatrixHeight();
    init_info.unit_utilities = unit_utilities;

    Simulation simulation(&init_info);

    while (simulation.running()) {
        simulation.update();
    }

    return 0;
}