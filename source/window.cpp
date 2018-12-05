#include "window.hpp"

#include "game_object.hpp"

void my::window::process_events()
{
	sf::Event event;
	while (this->pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->close();
		}
	}
}

void my::window::draw(game_object * const go)
{
	go->draw(*this);
}
