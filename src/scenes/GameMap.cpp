#pragma once
#include <string>
#include <fstream>
#include "GameMap.h"
#include "json.hpp"
using json = nlohmann::json;

Cell GameMap::map_char_to_cell(char tile, const json& terrain_defaults, const json& terrain_legend) {
	Cell cell;
	cell.symbol = tile;

	// Getting terrain from legend
	if (terrain_legend.contains(std::string(1, tile))) {
		cell.terrain_type = terrain_legend[std::string(1, tile)];
	}
	else {
		cell.terrain_type = "unknown";
	}

	// Set default values for cell from terrain
	

	return cell;
}

void GameMap::initialize_from_JSON(const std::string& filename) {
	std::ifstream file(filename);
	json parsed_file;
	file >> parsed_file;
}

Cell& GameMap::get_cell(int x, int y) {

}

Cell& GameMap::get_random_cell_with_biome(std::string biome) {

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
