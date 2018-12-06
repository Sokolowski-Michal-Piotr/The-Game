#pragma once

#include <SFML/System.hpp>

#include "window.hpp"
#include "resource_manager.hpp"

namespace my
{
    class game_object
    {
    public:
        virtual void init(const resource_manager& resources, const window& window) = 0;
        virtual void process_input() = 0;
        virtual void update(const sf::Time time_step) = 0;
        virtual void draw(window& window) = 0;
    };
}
