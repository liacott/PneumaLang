#include <unordered_map>
#include <random>
#include "CivManager.h"
#include "../map/GameMap.h"
#include "../map/Cell.h"
#include "../map/Point.h"

struct Civ;

Civ& CivManager::get_civ(const std::string& id) {
	return civ_registry.at(id);
}

bool CivManager::exists(const std::string& id) const {
	return civ_registry.find(id) != civ_registry.end();
}

std::string CivManager::create_civ(const std::string& civ_name, cell_RGB color) {
	std::string id = "civ_" + std::to_string(++civ_counter);
	Civ civ{ id, civ_name, color, 0 };
	civ_registry[id] = civ;
	return id;
}

void CivManager::generate_initial_civs(int initial_civ_count) {

}

void CivManager::generate_initial_borders(GameMap& map, int border_jitter) {
	// Vector of civ IDs to assign to cells
	std::vector<std::string> civ_ids;
	civ_ids.reserve(civ_registry.size());
	for (auto& [id, civ] : civ_registry) {
		civ_ids.push_back(id);
	}

	// MIGHT USE LATER
	//std::sort(civ_ids.begin(), civ_ids.end());

	// Valid points for civs to generate from (no oceans)
	std::vector<Point> valid_seeds;
	for (int y = 0; y < map.height; ++y) {
		for (int x = 0; x < map.width; ++x) {
			if (map.cell_grid[y][x].terrain_type != "ocean") {
				valid_seeds.push_back({ x, y });
			}
		}
	}

	// Randomize valid seed list and choose one for each initial civ
	std::shuffle(valid_seeds.begin(), valid_seeds.end(), rng);
	std::vector<Point> chosen_seeds;
	for (size_t i = 0; i < civ_registry.size() && i < valid_seeds.size(); ++i) {
		chosen_seeds.push_back(valid_seeds[i]);
	}

	// Distance-based territory control generation for each cell
	for (int y = 0; y < map.height; ++y) {
		for (int x = 0; x < map.width; ++x) {
			Cell& target_cell = map.cell_grid[x][y];

			// Skip oceans in generation
			if (target_cell.terrain_type == "ocean") continue;

			// Find closest seed among valid generated seeds
			int best_index = 0;
			double best_dist = std::numeric_limits<double>::max();

			for (size_t i = 0; i < chosen_seeds.size(); ++i) {
				double dist_x = x - chosen_seeds[i].x;
				double dist_y = y - chosen_seeds[i].y;
				double approx_dist = (dist_x * dist_x) + (dist_y * dist_y);

				if (approx_dist < best_dist) {
					best_dist = approx_dist;
					best_index = i; // At end of loop, best seed to assign cell to
				}
			}
			// Set control of the cell by best index
			target_cell.controlling_civ_id = civ_ids[best_index];
		}
	}
}