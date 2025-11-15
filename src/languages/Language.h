#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct Variety {
	std::string var_id;
	std::string name;
	double covert_prestige_factor = 1.0;	// Multiplied by base_prestige of parent for prestige spread
	double overt_prestige_factor = 1.0;	// Multiplied by base_prestige of parent for prestige spread
};

struct Language {
	std::string lang_id;
	std::string name;
	std::string parent_id;

	double writing_complexity = 1.0;
	double base_prestige = 1.0;
	int total_speakers = 0;	// Total speakers of this language on the entire map

	int variety_counter = 0; // Counter for unique variety IDs for this language
};