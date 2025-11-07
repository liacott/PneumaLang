#pragma once

#include "../events/GameEventHandler.h"
#include "../Entity.h"
#include <iostream>

class Scene {

public:
	int id; // Scene IDs should be a 6 digit number of the format 1XXXXX
	GameEventHandler scene_event_handler;
	std::vector<Entity> scene_entities;

	int get_id();

	void add_entity(Entity new_entity);
	void remove_entity(int entity_id);
};