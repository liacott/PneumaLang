#pragma once

#include "../events/GameEventHandler.h"
#include <iostream>

class Scene {

public:
	int id; // Scene IDs should be a 6 digit number of the format 1XXXXX
	GameEventHandler local_event_handler;

	// Overload == as member function
	bool operator==(const Scene& other)
		const {
		return	id == other.id &&
			local_event_handler == other.local_event_handler;
	}

	int get_id();

	void display_interface(); // Render relevant in-game player interface
};