#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "window.hpp"
#include "utility.hpp"
#include "main_menu.hpp"
#include "resource_manager.hpp"

int main(int argc, char* argv[])
{
	my::window window; {
		window.create(sf::VideoMode(800, 600), "The Game");
		window.setVerticalSyncEnabled(true);
	}
	my::resource_manager resources; {
		resources.load(my::utility::strip(argv[0], 2) + "resources/");
	}
	my::main_menu main_menu; {
		main_menu.init(resources, window);
	}
	my::game_object * current_scene = &main_menu;

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		window.process_events();
		current_scene->process_input();
		current_scene->update(elapsed);
		window.clear(sf::Color::White);
		window.draw(current_scene);
		window.display();
	}

	return EXIT_SUCCESS;
}
