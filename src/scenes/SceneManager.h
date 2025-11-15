#pragma once
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <functional>
#include <map>
#include "SceneState.h"

using RebuildCallback = std::function<void()>; // Callback type for rebuilding root container

class SceneManager {

private:

	std::shared_ptr<SceneState> state_;

	std::map<Scene, int> selected_indices_;

	// Build individual scenes
	ftxui::Component build_main_menu(RebuildCallback request_rebuild);
	ftxui::Component build_load_menu(RebuildCallback request_rebuild);
	ftxui::Component build_settings_menu(RebuildCallback request_rebuild);
	ftxui::Component build_spirit_select(RebuildCallback request_rebuild);
	//ftxui::Component build_game_view(bool hardmode);

public:
	SceneManager(std::shared_ptr<SceneState> state);
	ftxui::Component build_scene(Scene scene, RebuildCallback rebuild_scene);
};