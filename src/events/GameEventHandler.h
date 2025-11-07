#pragma once

#include <iostream>
#include <vector>
#include "GameEvent.h"

// Class to resolve a queue of events in a scene
class GameEventHandler {

	std::vector<GameEvent> queue;

public:
	
	void resolve_next();

	void queue_event(GameEvent ev); 
	void insert_event_at(int pos, GameEvent ev);
	void remove_event_at(int pos, GameEvent ev); 
	void clear_queue();
};