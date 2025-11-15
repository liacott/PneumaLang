#pragma once

#include <unordered_map>
#include <random>
#include "../map/GameMap.h"
#include "../map/Cell.h"

struct Civ;

class CivManager {

	std::unordered_map<std::string, Civ> civ_registry;
	int civ_counter;

public:
	
	std::mt19937 rng{ std::random_device{}() };
	
	// Access and modify civilization data
	Civ& get_civ(const std::string& id);
	bool exists(const std::string& id) const;
	cell_RGB get_map_color(const std::string& civ_id) {
		return civ_registry[civ_id].map_color;
	}

	// Add a new civ to registry and return ID
	std::string create_civ(const std::string& civ_name, cell_RGB color);

	void generate_initial_civs(int initial_civ_count = 6);

	// Voronoi-based intial border generation
	void generate_initial_borders(GameMap& map, int border_jitter = 0);
};