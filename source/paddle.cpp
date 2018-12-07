#include "paddle.hpp"

void my::paddle::init(const resource_manager& resources, const window& window)
{
    setTexture(resources.textures("paddle"));
    setScale(0.4f, 0.4f);
    auto bounds = getGlobalBounds();
    auto position = sf::Vector2f(window.getSize());
    position.x /= 2.0f;
    position.x -= bounds.width / 2;
    position.y -= bounds.height;
    setPosition(position);
    window_ = &window;
}

void my::paddle::process_input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity_ = -max_velocity_;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity_ = max_velocity_;
    else
        velocity_ = sf::Vector2f(0.0f, 0.0f);
}

void my::paddle::update(const sf::Time time_step)
{
    auto updated_position = getPosition() + velocity_ * time_step.asSeconds();

    auto bbox = getGlobalBounds();
    auto x_limit = window_->getSize().x - bbox.width;
    auto y_limit = window_->getSize().y - bbox.height;

    if (updated_position.x < 0.0f || updated_position.x > x_limit)
        velocity_.x *= -1.0f;
    else if (updated_position.y < 0.0f || updated_position.y > y_limit)
        velocity_.y *= -1.0f;

    updated_position.x = std::max(0.0f, std::min(updated_position.x, x_limit));
    updated_position.y = std::max(0.0f, std::min(updated_position.y, y_limit));

    setPosition(updated_position);
}

void my::paddle::draw(window & window)
{
    window.draw(*this);
}

void my::paddle::max_velocity(const sf::Vector2f & max_velocity)
{
    max_velocity_ = max_velocity;
}

const sf::Vector2f & my::paddle::max_velocity() const
{
    return max_velocity_;
}
