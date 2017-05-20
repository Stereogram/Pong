#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "State.h"
#include "EventMap.h"

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
	EventMap _events;
	sf::Event _event;
	sf::Font _font;
	sf::Text _text;
};
