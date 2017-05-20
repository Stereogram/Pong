﻿#include "IntroState.h"

#include <SFML/Graphics.hpp>
#include "EventMap.h"
#include "StateMachine.h"

IntroState::IntroState(StateMachine& machine, sf::RenderWindow& window, bool replace): State(machine, window, replace)
{
	_font.loadFromFile("arial.ttf");
	_text.setFont(_font);
	_text.setFillColor(sf::Color::White);
	_text.setString("intro");
	_events.Register(sf::Event::Closed, [this](sf::Event _event) {_machine.quit(); });
	_events.Register(sf::Event::KeyPressed, [this](sf::Event _event) {this->_text.setString(std::to_string(_event.key.code)); });
}

void IntroState::pause()
{
}

void IntroState::resume()
{
}

void IntroState::update(const sf::Time& dt)
{
	while (_window.pollEvent(_event))
	{
		_events.Invoke(_event);
	}
}

void IntroState::draw() const
{
	_window.clear(sf::Color::Black);
	_window.draw(_text);
	_window.display();
}

IntroState::~IntroState()
{
}
