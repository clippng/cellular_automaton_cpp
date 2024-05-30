cmake_minimum_required(VERSION 3.10)

add_executable(
	CellularAutomaton

	main.cpp

	simulation.cpp
	unit_utilities.cpp
	matrix.cpp
	cell.cpp
	display.cpp
)

target_link_libraries(CellularAutomaton sfml-graphics sfml-audio sfml-window sfml-system)