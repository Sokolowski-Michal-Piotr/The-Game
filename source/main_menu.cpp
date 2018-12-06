#include "main_menu.hpp"

#include <vector>
#include <iostream>

void my::main_menu::init(const resource_manager & resources, const window & window)
{
	rng.seed(std::random_device{});
	init_logo(resources, window);
	init_balls(resources, window, rng);
}

void my::main_menu::process_input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && signal != nullptr) {
		std::cout << "Setup null animation." << std::endl;
		signal = nullptr;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && signal != &linear) {
		std::cout << "Setup linear animation." << std::endl;
		signal = &linear;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && signal != &sine) {
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

		float updated_scale = initial_scale + max_scale_offset * signal->value();
		logo.setScale(sf::Vector2f(updated_scale, updated_scale));
	}

	for (auto& ball : balls)
		ball.update(time_step);
}

void my::main_menu::draw(window& window)
{
	window.clear(sf::Color::White);
	for (auto& ball : balls)
		window.draw(ball);
	window.draw(logo);
}

void my::main_menu::init_logo(const resource_manager & resources, const window & window)
{
	signal = nullptr;
	logo.setFont(resources.fonts("bebas_neue"));
	logo.setString(L"The Game");
	logo.setCharacterSize(80);
	logo.setFillColor(sf::Color(219, 32, 44));
	logo.setOutlineColor(sf::Color::Black);
	logo.setOutlineThickness(1.0f);
	const auto bounds = logo.getGlobalBounds();
	sf::Vector2f origin = { bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f };
	logo.setOrigin(origin);
	logo.setPosition(sf::Vector2f(window.getSize()) / 2.0f);
	logo.setScale(initial_scale, initial_scale);
}

void my::main_menu::init_balls(const resource_manager & resources, const window & window, xorshift & rng)
{
	const float max_speed = 500.0f;
	const std::vector<float> intervals = {
		-max_speed,
		-max_speed / 2,
		0.0f,
		max_speed / 2,
		max_speed
	};
	const std::vector<float> weights = {
		0.0f,
		1.0f,
		0.0f,
		1.0f,
		0.0f
	};
	std::piecewise_linear_distribution<float>
		velocity_distr(intervals.begin(), intervals.end(), weights.begin());

	const auto window_size = sf::Vector2f(window.getSize());
	std::uniform_real_distribution<float> pos_x_distr(0.0f, window_size.x);
	std::uniform_real_distribution<float> pos_y_distr(0.0f, window_size.y);

	balls.resize(10);
	for (auto& ball : balls)
	{
		sf::Vector2f velocity = {
			velocity_distr(rng),
			velocity_distr(rng)
		};
		sf::Vector2f position = {
			pos_x_distr(rng),
			pos_y_distr(rng)
		};
		ball.init(resources, window);
		ball.velocity(velocity);
		ball.setPosition(position);
	}
}
