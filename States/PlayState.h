#pragma once
#include "State.h"

class PlayState : public State
{
public:
	PlayState(StateMachine& machine, sf::RenderWindow& window, bool replace);
	~PlayState() override;
	void pause() override;
	void resume() override;
	void update(const sf::Time&) override;
	void draw() const override;
};
