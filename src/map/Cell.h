#pragma once
#include <string>
#include <random>
#include "MapMode.h"

struct Cell {
	char symbol; // Symbol on map (terrain based)

	std::string terrain_type; // Terrain type
	bool habitable; // Determines whether nations can expand into this cell.
	int population; // Number of pops living in cell
	double multiling_factor; // Ratio of total max speaker count to population. (1-5)
	double drift_resist; // Resistance to speaker count changes from terrain. (0-1)

	int total_max_speakers; // Population modified for avg multilingualism in cell
	double isolation; // Speeds up language divergence from geographic separation. (0-1)
	std::string controlling_civ_id; // Nation that currently controls this cell.
};

struct cell_RGB { float r, g, b; };

cell_RGB get_political_color(const std::string& controlling_civ) {
	return cell_RGB{ 1,1,1 };
}

cell_RGB get_terrain_color(const std::string& terrain_type) {
	if (terrain_type == "ocean") return		{ 0.3f, 0.4f, 1.0f };
	if (terrain_type == "plain") return		{ 0.3f, 0.9f, 0.3f };
	if (terrain_type == "forest") return	{ 0.2f, 0.5f, 0.2f };
	if (terrain_type == "mountain") return	{ 0.9f, 0.2f, 0.1f };
	if (terrain_type == "desert") return	{ 0.9f, 0.9f, 0.4f };
	if (terrain_type == "urban") return		{ 1.0f, 0.5f, 1.0f };
	return { 0.0f, 0.0f, 0.0f };
}

cell_RGB get_random_color() {
	return cell_RGB{ 1,1,1 };
}