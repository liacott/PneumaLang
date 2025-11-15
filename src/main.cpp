#include "scenes/SceneManager.h"
#include "scenes/SceneState.h"
#include <ftxui/component/screen_interactive.hpp>
#include <functional>	// for functionn
#include <memory>		// for make_shared & shared_ptr
#include <utility>		// for forward
#include <iostream>

int main()
{
	// Console window we are displaying to
	auto screen = ftxui::ScreenInteractive::Fullscreen();

	// Scene manager and scene state manager with main menu as default
	auto state = std::make_shared<SceneState>();
	state->current_scene = Scene::MainMenu;
	state->next_scene = Scene::MainMenu;
	state->pending_scene_switch = false;
	SceneManager manager(state);

	// Container to hold currrent scene
	auto root_container = ftxui::Container::Vertical({});

	// Declaring callbacks
	std::function<void()> rebuild_scene;
	std::function<void()> request_rebuild;
	
	// Triggers deferred rebuild
	request_rebuild = [&] {
        screen.PostEvent(ftxui::Event::Custom);   
    };

	// Replaces and builds scene
	rebuild_scene = [&] {
        root_container->DetachAllChildren();
		root_container->Add(manager.build_scene(state->current_scene, request_rebuild));
    };

	// Build first scene
	rebuild_scene();

	auto container_with_events = CatchEvent(root_container, [&](ftxui::Event event) {
        if (event == ftxui::Event::Custom) {
            if (state->pending_scene_switch) {
                state->pending_scene_switch = false;
                state->current_scene = state->next_scene;
                rebuild_scene();
            }
            return true;
        }
        return false;
    });

	screen.Loop(container_with_events);
	return 0;

}
