#include "IntroState.h"

void IntroState::pause()
{
}

void IntroState::resume()
{
}

void IntroState::update()
{
}

void IntroState::draw()
{
	_window.clear(sf::Color::Black);
	_window.draw(_text);
	_window.display();
}
