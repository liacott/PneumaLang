#pragma once
#include <vector>
#include <string>
#include "Cell.h"
#include "json.hpp"
using json = nlohmann::json;

class GameMap {
	std::vector<std::vector<Cell>> map_grid;
	int width;
	int height;
	std::string map_mode;

public:
	
	GameMap(int w, int h) {
		width = w;
		height = h;
	}

	Cell map_char_to_cell(char tile, const json& terrain_defaults, const json& terrain_legend);
	void initialize_from_JSON(const std::string& filename);

	Cell& get_cell(int x, int y);
	Cell& get_random_cell_with_biome(std::string biome);
	
	void update_population_shift();
	void update_population_map();

	void update_language_shift();
	void update_language_map();

	void update_political_shift();
	void update_political_map();

	void update_terrain_shift();
	void update_terrain_map();

	void print_map() const;
	

};

