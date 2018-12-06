#pragma once

#include <SFML\System.hpp>

namespace my
{
    namespace signals
    {
        class signal
        {
        public:
            virtual void update(sf::Time time_step) = 0;
            float value() const;
        protected:
            float value_ = 0.0;
        };

        class linear : public signal
        {
        public:
            void update(sf::Time time_step) override;
        protected:
            float sign = 1.0f;
        };

        class sine : public signal
        {
        public:
            void update(sf::Time time_step) override;
        protected:
            float accumulator_ = 0.0;
        };
    }
}