#include "SceneManager.h"
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>

SceneManager::SceneManager(std::shared_ptr<SceneState> state) : state_(state) {} 

ftxui::Component SceneManager::build_main_menu(RebuildCallback request_rebuild) {
	
	// Selected menu index
	if (selected_indices_.find(Scene::MainMenu) == selected_indices_.end())
		selected_indices_[Scene::MainMenu] = 0;

	auto& selected = selected_indices_[Scene::MainMenu];

	// Menu entries
	static std::vector<std::string> entries = {
		"New Game",
		"Load Game",
		"Settings",
		"Quit"
	};

	// Renderer for menu
	auto menu = ftxui::Menu({
		.entries = &entries,
		.selected = &selected
	})  | ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 20)
		| ftxui::hcenter;

	auto menu_renderer = ftxui::Renderer(menu, [menu] {
		return menu->Render();
	});

	// Handle user input and selection
	auto menu_with_events = ftxui::CatchEvent(menu_renderer, 
		[this, &selected, request_rebuild](ftxui::Event event) {
			if (event == ftxui::Event::Return) {
				switch (selected) {
					case 0: state_->next_scene = Scene::SpiritSelect; break;
					case 1: state_->next_scene = Scene::LoadMenu; break;
					case 2: state_->next_scene = Scene::Settings; break;
					case 3: state_->next_scene = Scene::Exit; break;
				}

				state_->pending_scene_switch = true;
				request_rebuild(); // Rebuild immediately on change
				return true;
			}
			return false;
		});

	// Renderer for the whole layout
	return ftxui::Renderer(menu_with_events, [menu_with_events] {
        return ftxui::vbox({
            ftxui::text("PNEUMALANG")
                | ftxui::bold
                | ftxui::color(ftxui::Color::Green)
                | ftxui::hcenter,
            ftxui::separator() | ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 20),
            menu_with_events->Render()
        }) | ftxui::center;
    });
}

ftxui::Component SceneManager::build_load_menu(RebuildCallback request_rebuild) {
	// Selected menu index
	if (selected_indices_.find(Scene::LoadMenu) == selected_indices_.end())
		selected_indices_[Scene::LoadMenu] = 0;

	auto& selected = selected_indices_[Scene::Settings];

	// Options
	static std::vector<std::string> menu_options{
		"Back"
	};

	// Menu component
	auto menu = ftxui::Menu({ 
		.entries = &menu_options, 
		.selected = &selected 
	});

	// Renderer for menu
	auto menu_renderer = ftxui::Renderer(menu, [menu] {
		return menu->Render();
	});

	// Handle user input and selection
	auto menu_with_events = ftxui::CatchEvent(menu_renderer, 
		[this, &selected, request_rebuild](ftxui::Event event) {
			if (event == ftxui::Event::Return) {
				switch (selected) {
					case 0: state_->next_scene = Scene::MainMenu; break;
				}
				state_->pending_scene_switch = true;
				request_rebuild(); // Rebuild immediately on change
				return true;
			}
			return false;
		});

	// Renderer for the whole layout
	return ftxui::Renderer(menu_with_events, [menu_with_events] {
        return ftxui::vbox({
            ftxui::text("LOAD GAME")
                | ftxui::bold
                | ftxui::color(ftxui::Color::Red)
                | ftxui::hcenter,
            ftxui::separator() | ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 20),
            menu_with_events->Render()
        }) | ftxui::vcenter;
    });
}

ftxui::Component SceneManager::build_settings_menu(RebuildCallback request_rebuild) {
	
	// Selected menu index
	if (selected_indices_.find(Scene::Settings) == selected_indices_.end())
		selected_indices_[Scene::Settings] = 0;

	auto& selected = selected_indices_[Scene::Settings];

	// Options
	static std::vector<std::string> menu_options{
		"Back"
	};

	// Menu component
	auto menu = ftxui::Menu({ 
		.entries = &menu_options, 
		.selected = &selected 
	});

	// Renderer for menu
	auto menu_renderer = ftxui::Renderer(menu, [menu] {
		return menu->Render();
	});

	// Handle user input and selection
	auto menu_with_events = ftxui::CatchEvent(menu_renderer, 
		[this, &selected, request_rebuild](ftxui::Event event) {
			if (event == ftxui::Event::Return) {
				switch (selected) {
					case 0: state_->next_scene = Scene::MainMenu; break;
				}
				state_->pending_scene_switch = true;
				request_rebuild(); // Rebuild immediately on change
				return true;
			}
			return false;
		});

	// Renderer for the whole layout
	return ftxui::Renderer(menu_with_events, [menu_with_events] {
        return ftxui::vbox({
            ftxui::text("SETTINGS")
                | ftxui::bold
                | ftxui::color(ftxui::Color::Red)
                | ftxui::hcenter,
            ftxui::separator() | ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 20),
            menu_with_events->Render()
        }) | ftxui::vcenter;
    });
}

ftxui::Component SceneManager::build_spirit_select(RebuildCallback request_rebuild) {
	
	// Selected menu index
	if (selected_indices_.find(Scene::SpiritSelect) == selected_indices_.end())
		selected_indices_[Scene::SpiritSelect] = 0;

	auto& selected = selected_indices_[Scene::SpiritSelect];

	// Options
	static std::vector<std::string> menu_options{
		"Spirit of Song",
		"Spirit of Prose",
		"Spirit of Drama",
		"Spirit of Rhetoric",
		"Back"
	};

	// Menu component
	auto menu = ftxui::Menu({ 
		.entries = &menu_options, 
		.selected = &selected 
	});

	// Renderer for menu
	auto menu_renderer = ftxui::Renderer(menu, [menu] {
		return menu->Render();
	});

	// Handle user input and selection
	auto menu_with_events = ftxui::CatchEvent(menu_renderer, 
		[this, &selected, request_rebuild](ftxui::Event event) {
			if (event == ftxui::Event::Return) {
				switch (selected) {
					case 0: state_->next_scene = Scene::GameView; break;
					case 1: state_->next_scene = Scene::GameView; break;
					case 2: state_->next_scene = Scene::GameView; break;
					case 3: state_->next_scene = Scene::GameView; break;
					case 4: state_->next_scene = Scene::MainMenu; break;
				}
				state_->pending_scene_switch = true;
				request_rebuild(); // Rebuild immediately on change
				return true;
			}
			return false;
		});

	// Renderer for the whole layout
	return ftxui::Renderer(menu_with_events, [menu_with_events] {
        return ftxui::vbox({
            ftxui::text("WHO ARE YOU?")
                | ftxui::bold
                | ftxui::color(ftxui::Color::Blue)
                | ftxui::hcenter,
            ftxui::separator() | ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 20),
            menu_with_events->Render()
        }) | ftxui::center;
    });
}

//ftxui::Component SceneManager::build_game_view(bool hardmode) {
	// TODO
//}

ftxui::Component SceneManager::build_scene(Scene scene, RebuildCallback rebuild_scene) {
	switch (scene) {
	case Scene::MainMenu:
		return build_main_menu(rebuild_scene);
	case Scene::LoadMenu:
		return build_load_menu(rebuild_scene);
	case Scene::Settings:
		return build_settings_menu(rebuild_scene);
	case Scene::Exit:
		return ftxui::Renderer(nullptr, [] { return ftxui::text("Exiting..."); });
	case Scene::SpiritSelect:
		return build_spirit_select(rebuild_scene);	
	}
	return build_main_menu(rebuild_scene); // Default
}