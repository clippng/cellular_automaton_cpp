cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(CellularAutomaton)

add_subdirectory(cellular_automaton)

set(SFML_DIR "/usr/include/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio network system window REQUIRED)
