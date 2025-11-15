#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Cell.h"
#include "MapMode.h"
#include "json.hpp"
#include "../humanity/Civ.h"

class CivManager;

using json = nlohmann::json;

class GameMap {
	
public:
	
	int width;
	int height;

	GameMap(int w, int h) {
		width = w;
		height = h;
	}

	std::vector<std::vector<Cell>> cell_grid;

	std::unordered_map<std::string, cell_RGB> language_colors;
	std::unordered_map<std::string, cell_RGB> civ_colors;
	std::unordered_map<std::string, cell_RGB> terrain_colors;

	MapMode active_map_mode;

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

