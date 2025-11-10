#pragma once
#include <string>
#include <unordered_map>

struct Language {
	std::string id;
	std::string parent_ID;
	double writing_complexity;
	double prestige;
	int total_speakers;
};

class LanguageManager {

	std::unordered_map<std::string, Language> language_registry;
	int lang_counter = 0; // Counter for number of unique language IDs

public:
	// Access and modify language data
	Language& get_language(const std::string& id);
	bool exists(const std::string& id) const;
	
	// Add a new language to the registry and return its ID
	std::string create_language(const std::string& parent_ID);

};