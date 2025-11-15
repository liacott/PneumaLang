#include "LanguageManager.h"

Language& LanguageManager::get_language(const std::string& id) {
	return language_registry.at(id);
}

bool LanguageManager::exists(const std::string& id) const {
	return language_registry.find(id) != language_registry.end();
}

std::string LanguageManager::create_language(std::string lang_name, const std::string& parent_ID) {
	std::string id = "lang_" + std::to_string(++lang_counter);
	Language lang{ id, lang_name, parent_ID, 1.0, 1.0, 0 };
	language_registry[id] = lang;
	return id;
}

std::string LanguageManager::create_variety(std::string var_name, Language& core_lang) {
	std::string id = core_lang.lang_id 
		+ "_var_" + std::to_string(++core_lang.variety_counter);
	Variety var{ id, var_name, 1.0, 1.0 };
	return id;
}