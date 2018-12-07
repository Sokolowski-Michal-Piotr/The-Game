#include "ball.hpp"

void my::ball::init(const resource_manager& resources, const window& window)
{
    setTexture(resources.textures("ball"));
    setScale(0.4f, 0.4f);
    window_ = &window;
}

void my::ball::process_input()
{
    
}

void my::ball::update(const sf::Time time_step)
{
    auto updated_position = getPosition() + velocity_ * time_step.asSeconds();

    auto bbox = getGlobalBounds();
    auto x_limit = window_->getSize().x - bbox.width;
    auto y_limit = window_->getSize().y - bbox.height;

    if (updated_position.x < 0.0f || updated_position.x > x_limit)
        velocity_.x *= -1.0f;
    else if (updated_position.y < 0.0f)
        velocity_.y *= -1.0f;

    updated_position.x = std::max(0.0f, std::min(updated_position.x, x_limit));
    updated_position.y = std::max(0.0f, updated_position.y);

    setPosition(updated_position);
}

void my::ball::draw(window & window)
{
    window.draw(*this);
}

void my::ball::velocity(const sf::Vector2f & velocity)
{
    velocity_ = velocity;
}

const sf::Vector2f & my::ball::velocity() const
{
    return velocity_;
}
