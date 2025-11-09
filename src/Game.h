#include "scenes/Scene.h"
#include <iostream>
#include <map>

class Game {
public:
	std::map<int, Scene> game_scenes;

	void load_scene(int target_id);
	void render_scene();
	void initialize_scenes();
	
	void run();
};