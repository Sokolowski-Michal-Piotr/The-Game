#pragma once

#include <SFML/System.hpp>

namespace my
{
	class window;

	class game_object
	{
	public:
		virtual void process_input() = 0;
		virtual void update(const sf::Time time_step) = 0;
		virtual void draw(window& window) = 0;
	};
}
