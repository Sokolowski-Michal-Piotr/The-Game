#pragma once

#include <SFML/Graphics.hpp>

#include "game_object.hpp"

namespace my
{
    class ball : public game_object, public sf::Sprite
    {
    public:
        void init(const resource_manager& resources, const window& window) override;
        void process_input() override;
        void update(const sf::Time time_step) override;
        void draw(window & window) override;

        void velocity(const sf::Vector2f& velocity);
        const sf::Vector2f& velocity() const;

    protected:
        sf::Vector2f velocity_;
        const window * window_;
    };
}
