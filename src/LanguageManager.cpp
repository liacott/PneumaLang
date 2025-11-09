#include "LanguageManager.h"

Language& LanguageManager::get_language(const std::string& id) {
	return language_registry.at(id);
}

bool LanguageManager::exists(const std::string& id) const {
	return language_registry.find(id) != language_registry.end();
}

std::string LanguageManager::create_language(const std::string& parent_ID = "") {
	std::string id = "lang_" + std::to_string(++lang_counter);
	Language lang{ id, parent_ID, 0.5, 0.5, 0 };
	language_registry[id] = lang;
	return id;
}