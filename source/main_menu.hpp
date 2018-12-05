#pragma once

#include "game_object.hpp"
#include "resource_manager.hpp"
#include "window.hpp"
#include "signals.hpp"

namespace my
{
	class main_menu : public game_object
	{
	public:
		void init(const resource_manager& resources, const window& window);
		void process_input() override;
		void update(const sf::Time time_step) override;
		void draw(window& window) override;

	protected:
		sf::Text logo;

		signals::sine sine;
		signals::linear linear;
		signals::signal * signal = &sine;

		const float initial_scale = 1.0f;
		const float max_scale_offset = 0.2f;
		const float signal_update_rate = 0.5f;
	};
}
