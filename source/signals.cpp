#include "signals.hpp"

#include "utility.hpp"

float my::signals::signal::value() const
{
    return value_;
}

void my::signals::linear::update(sf::Time time_step)
{
    value_ += time_step.asSeconds() * 4.0f * sign;

    if (value_ >= 1.0f || value_ <= -1.0f) 
    {
        sign *= -1.0f;
        float diff = fabs(value_) - 1.0f;
        value_ += 2.0f * diff * sign;
    }
}

void my::signals::sine::update(sf::Time time_step)
{
    accumulator_ += my::utility::pif2 * time_step.asSeconds();

    if (accumulator_ >= my::utility::pif2)
        accumulator_ -= my::utility::pif2;

    value_ = sin(accumulator_);
}
