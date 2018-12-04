#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>

#include "utility.hpp"
#include "signals.hpp"

int main(int argc, char* argv[])
{
	std::cout << "Executable path: " << argv[0] << std::endl;

	std::string resources_path = my::utility::strip(argv[0], 2) + "resources/";
	std::cout << "Resources path: " << resources_path << std::endl;

	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");
	window.setVerticalSyncEnabled(true);

	sf::Font font; {
		font.loadFromFile(resources_path + "fonts/bebas_neue.otf");
	}

	sf::Text logo; {
		logo.setFont(font);
		logo.setString(L"The Game");
		logo.setCharacterSize(100);
		logo.setFillColor(sf::Color(219, 32, 44));
		logo.setOutlineColor(sf::Color::Black);
		logo.setOutlineThickness(0.66f);
		const auto bounds = logo.getLocalBounds();
		sf::Vector2f origin = { bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f };
		logo.setOrigin(origin);
		logo.setPosition(sf::Vector2f(window.getSize()) / 2.0f);
		logo.setScale(1.0f, 1.0f);
	}

	my::signals::sine sine;
	my::signals::linear linear;
	my::signals::signal * signal = &sine;

	const float max_scale_offset = 0.2f;
	const float signal_update_rate = 0.5f;
	const float initial_scale = logo.getScale().x;

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();

		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && signal != &linear) {
				std::cout << "Setup linear animation." << std::endl;
				signal = &linear;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && signal != &sine) {
				std::cout << "Setup sine animation." << std::endl;
				signal = &sine;
			}
		}

		if (signal) {
			auto signal_elapsed = sf::seconds(signal_update_rate * elapsed.asSeconds());
			sine.update(signal_elapsed);
			linear.update(signal_elapsed);

			float updated_scale = initial_scale + initial_scale * max_scale_offset * signal->value();
			logo.setScale(sf::Vector2f(updated_scale, updated_scale));
		}

		window.clear(sf::Color::White);
		window.draw(logo);
		window.display();
	}

	return EXIT_SUCCESS;
}
