#pragma once

#include <memory>

#include "matrix.hpp"
#include "unit_utilities.hpp"

struct SIMULATION_INIT_INFO {
    uint32_t columns;
    uint32_t rows;

    std::shared_ptr<UnitUtilities> unit_utilities;
};

class Simulation {
public:
    Simulation(SIMULATION_INIT_INFO *init_info);
    ~Simulation();

    const bool running();

    void update();
    void nextGeneration();
    void render();

private:
    struct WINDOW_DATA {
        sf::RenderWindow *window;
        sf::Vector2u window_size{};
        sf::Event event;
        sf::VideoMode video_mode;
        sf::Vector2i mouse_position_in_window;

        static constexpr uint32_t ticks_per_second = 60; 
        const uint32_t MAX_FRAME_RATE = 144;
        const sf::Time timePerUpdate = sf::seconds(1.0f / float(ticks_per_second));
    
        void updateMousePosition();
        void pollEvents();
    } window_data;

    struct MATRIX_DATA {
        uint32_t rows, columns;
        std::unique_ptr<Matrix> matrix_data;
        std::unique_ptr<Matrix> next_matrix_data;
        void update();
    } matrix_data;

    uint32_t generation;

    std::shared_ptr<UnitUtilities> unit_utilities;

    void initialiseVariables();
    void initialiseWindow();
};