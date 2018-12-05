#include "main_menu.hpp"

#include <iostream>

void my::main_menu::init(const resource_manager & resources, const window & window)
{
	logo.setFont(resources.fonts("bebas_neue"));
	logo.setString(L"The Game");
	logo.setCharacterSize(100);
	logo.setFillColor(sf::Color(219, 32, 44));
	logo.setOutlineColor(sf::Color::Black);
	logo.setOutlineThickness(0.66f);
	const auto bounds = logo.getLocalBounds();
	sf::Vector2f origin = { bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f };
	logo.setOrigin(origin);
	logo.setPosition(sf::Vector2f(window.getSize()) / 2.0f);
	logo.setScale(initial_scale, initial_scale);
}

void my::main_menu::process_input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && signal != &linear) {
		std::cout << "Setup linear animation." << std::endl;
		signal = &linear;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && signal != &sine) {
		std::cout << "Setup sine animation." << std::endl;
		signal = &sine;
	}
}

void my::main_menu::update(const sf::Time time_step)
{
	if (signal)
	{
		auto elapsed = sf::seconds(signal_update_rate * time_step.asSeconds());

		sine.update(elapsed);
		linear.update(elapsed);

		float updated_scale = initial_scale + initial_scale * max_scale_offset * signal->value();
		logo.setScale(sf::Vector2f(updated_scale, updated_scale));
	}
}

void my::main_menu::draw(window& window)
{
	window.draw(logo);
}
