#pragma once

#include <unordered_map>
#include <SFML\Graphics.hpp>

namespace my
{
	class resource_manager
	{
	public:
		void load(const std::string& root);
		const sf::Font& fonts(const std::string& id) const;
	protected:
		std::unordered_map<std::string, sf::Font> fonts_;
	};
}
