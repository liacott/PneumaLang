#pragma once
#include <string>
#include "../map/MapMode.h"
#include "../map/Cell.h"

// Struct for human civilizations
struct Civ {
	std::string civ_id;
	std::string name;
	cell_RGB map_color;

	int total_population;
};