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
        auto settings = sf::ContextSettings{}; settings.antialiasingLevel = 4;
        window.create(sf::VideoMode(800, 600), "The Game", sf::Style::Close, settings);
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
        window.clear(sf::Color::Magenta);
        current_scene->draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
