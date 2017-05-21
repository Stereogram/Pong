#pragma once

#include <SFML/Graphics/Text.hpp>
#include "State.h"

namespace sf {
	class Time;
}

class IntroState : public State
{
public:
	IntroState(StateMachine& machine, sf::RenderWindow& window, bool replace);

	void pause() override;
	void resume() override;
	void update(const sf::Time&) override;
	void draw() const override;
	~IntroState() override;
private:
	sf::Font _font;
	sf::Text _text;
};
