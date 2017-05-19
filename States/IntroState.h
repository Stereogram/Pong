#pragma once

#include <SFML/Graphics/Text.hpp>
#include "State.h"
#include "../Game.h"

class IntroState : public State
{
public:
	IntroState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State(machine, window, replace)
	{
		_font.loadFromFile("arial.ttf");
		_text.setFont(_font);
		_text.setFillColor(sf::Color::White);
		_text.setPosition(40, 40);
		_text.setString("intro");
		std::cout << "intro" << std::endl;
	}

	void pause() override;
	void resume() override;
	void update() override;
	void draw() override;
private:
	sf::Font _font;
	sf::Text _text;
};
