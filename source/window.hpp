#pragma once

#include <SFML/Graphics.hpp>

namespace my
{
	class game_object;

	class window : public sf::RenderWindow
	{
	public:
		void process_events();
		void draw(game_object * const go);
		using sf::RenderWindow::draw;
	};
}
