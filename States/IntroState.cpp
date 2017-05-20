#include "IntroState.h"

#include <SFML/Graphics.hpp>

void IntroState::pause()
{
}

void IntroState::resume()
{
}

void IntroState::update(const sf::Time& dt)
{
}

void IntroState::draw()
{
	_window.clear(sf::Color::Black);
	_window.draw(_text);
	_window.display();
}

IntroState::~IntroState()
{
}
