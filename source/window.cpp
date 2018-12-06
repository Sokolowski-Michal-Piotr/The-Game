#include "window.hpp"

void my::window::process_events()
{
    sf::Event event;
    while (this->pollEvent(event))
    {
        if (event.type == sf::Event::Closed ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->close();
        }
        //else if (event.type == sf::Event::Resized)
        //{
        //	sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        //	this->setView(sf::View(visibleArea));
        //}
    }
}
