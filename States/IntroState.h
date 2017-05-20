#pragma once

#include <SFML/Graphics/Text.hpp>
#include "State.h"

namespace sf {
	class Time;
}

class IntroState : public State
{
public:
	IntroState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State(machine, window, replace)
	{
		_font.loadFromFile("arial.ttf");
		_text.setFont(_font);
		_text.setFillColor(sf::Color::White);
		_text.setString("intro");
	}

	void pause() override;
	void resume() override;
	void update(const sf::Time&) override;
	void draw() override;
	~IntroState() override;
private:
	sf::Font _font;
	sf::Text _text;
};
