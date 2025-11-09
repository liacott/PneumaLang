#pragma once
#include <string>

struct Language {
	std::string id;
	std::string parent_ID;
	double isolation; // Increases while speakers are isolated geographically
};