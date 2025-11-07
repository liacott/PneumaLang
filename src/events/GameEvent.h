#pragma once

#include <iostream>

// Super class to handle all in game events and entity interactions
class GameEvent {
public:
	int id; // GameEvent ids should be a 6 digit number of the format 3XXXXX
	std::string name;

	GameEvent(int x, std::string n) {
		id = x;
		name = n;
	}

	// Overload == as member function
	bool operator==(const GameEvent& other)
	const {
		return	id == other.id &&
				name == other.name;
	}

	// Getters
	int get_id();
	std::string get_name();

};