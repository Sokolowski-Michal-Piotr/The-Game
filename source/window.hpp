#pragma once

#include <SFML/Graphics.hpp>

namespace my
{
	class window : public sf::RenderWindow
	{
	public:
		void process_events();
	};
}
