#pragma once
#include <string>

struct Cell {
	std::string terrain_type; // Terrain type from symbol
	char symbol; // Symbol on map (terrain based)
	bool habitable; // Determines whether nations can expand into this cell.
	int population;
	double multiling_factor; // Ratio of total max speaker count to population. (1-5)
	double total_max_speakers; // Population modified for avg multilingualism in cell
	double drift_resist; // Resistance to speaker count changes from terrain. (0-1)
	double isolation; // Speeds up language divergence from geographic separation. (0-1)
	std::string nation_ID; // Nation that currently controls this cell.
};