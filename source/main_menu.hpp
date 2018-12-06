#pragma once

#include <vector>

#include "game_object.hpp"
#include "resource_manager.hpp"
#include "window.hpp"
#include "signals.hpp"
#include "ball.hpp"
#include "xorshift.hpp"

namespace my
{
	class main_menu : public game_object
	{
	public:
		void init(const resource_manager& resources, const window& window) override;
		void process_input() override;
		void update(const sf::Time time_step) override;
		void draw(window& window) override;

	protected:
		void init_logo(const resource_manager & resources, const window & window);
		void init_balls(const resource_manager & resources, const window & window, xorshift & rng);

		my::xorshift rng;

		sf::Text logo;

		signals::sine sine;
		signals::linear linear;
		signals::signal * signal;

		const float initial_scale = 1.0f;
		const float max_scale_offset = 0.175f;
		const float signal_update_rate = 0.55f;

		std::vector<ball> balls;
	};
}
