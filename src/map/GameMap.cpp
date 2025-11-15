#pragma once
#include <string>
#include <fstream>
#include "GameMap.h"
#include "json.hpp"
using json = nlohmann::json;

Cell GameMap::map_char_to_cell(char tile, const json& terrain_defaults, const json& terrain_legend) {
	Cell target_cell;
	target_cell.symbol = tile;

	// Getting terrain from legend
	if (terrain_legend.contains(std::string(1, tile))) {
		target_cell.terrain_type = terrain_legend[std::string(1, tile)];
	}
	else {
		target_cell.terrain_type = "unknown";
	}

	// Set some default values for cell from terrain
	if (terrain_defaults.find(target_cell.terrain_type) != terrain_defaults.end()) {
		target_cell.habitable = 
			terrain_defaults[target_cell.terrain_type]["habitable"];
		target_cell.population = 
			terrain_defaults[target_cell.terrain_type]["population"];
		target_cell.multiling_factor = 
			terrain_defaults[target_cell.terrain_type]["multiling_factor"];
		target_cell.drift_resist = 
			terrain_defaults[target_cell.terrain_type]["drift_resist"];
	}
	else {
		// Defaults in case terrain type is not found
		target_cell.habitable = false;
		target_cell.population = 0;
		target_cell.multiling_factor = 0.0;
		target_cell.drift_resist = 0.0;
	}

	// Total max speakers rounded up
	target_cell.total_max_speakers = std::round((target_cell.population * target_cell.multiling_factor) + 0.5);
	
	target_cell.isolation = 0.0;

	target_cell.controlling_civ_id = "";

	return target_cell;
}

void GameMap::initialize_from_JSON(const std::string& filename) {
	std::ifstream file(filename);
	json parsed_file;
	file >> parsed_file;
}

Cell& GameMap::get_cell(int x, int y) {
	Cell cell;
	return cell;
}

Cell& GameMap::get_random_cell_with_biome(std::string biome) {
	Cell cell;
	return cell;
}

void GameMap::update_population_shift() {

}

void GameMap::update_population_map() {

}

void GameMap::update_language_shift() {

}

void GameMap::update_language_map() {

}

void GameMap::update_political_shift() {

}

void GameMap::update_political_map() {

}

void GameMap::update_terrain_shift() {

}

void GameMap::update_terrain_map() {

}

void GameMap::print_map() const {

}
