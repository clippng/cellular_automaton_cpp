cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(CellularAutomaton)

include_directories(cellular_automaton)

add_executable(
CellularAutomaton 
cellular_automaton/main.cpp
cellular_automaton/main.hpp

cellular_automaton/simulation.cpp
cellular_automaton/unit_utilities.cpp
cellular_automaton/matrix.cpp
cellular_automaton/cell.cpp
cellular_automaton/rule_set.cpp
cellular_automaton/display.cpp

cellular_automaton/simulation.hpp
cellular_automaton/unit_utilities.hpp
cellular_automaton/matrix.hpp
cellular_automaton/cell.hpp
cellular_automaton/rule_set.hpp
cellular_automaton/display.hpp
)

set(SFML_DIR "/usr/include/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(CellularAutomaton sfml-graphics sfml-audio)