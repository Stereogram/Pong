#pragma once
#include <memory>
#include <SFML/System/Time.hpp>
#include "EventMap.h"

class StateMachine;
namespace sf
{
	class RenderWindow;
}

class State
{
public:
	State(StateMachine& machine, sf::RenderWindow& window, bool replace = true)
	: _machine(machine)
	, _window(window)
	, _replacing(replace)
	{
	}
	virtual ~State() = default;
	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void update(const sf::Time&) = 0;
	virtual void draw()const = 0;

	auto next() { return std::move(_next); }
	auto isReplacing() { return _replacing; }

protected:
	EventMap _events;
	sf::Event _event;
	StateMachine& _machine;
	sf::RenderWindow& _window;
	bool _replacing;
	std::unique_ptr<State> _next;
};