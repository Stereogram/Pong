#pragma once
#include <memory>
#include <iostream>


class StateMachine;
namespace sf
{
	class RenderWindow;
}

class State
{
public:
	State(StateMachine& machine, sf::RenderWindow& window, bool replace = true)
	:_machine(machine)
	, _window(window)
	, _replacing(replace)
	{
		std::cout << "State" << std::endl;
	}
	virtual ~State() = default;
	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void update() = 0;
	virtual void draw() = 0;

	auto next() { return std::move(_next); }
	auto isReplacing() { return _replacing; }

protected:
	StateMachine& _machine;
	sf::RenderWindow& _window;
	bool _replacing;
	std::unique_ptr<State> _next;
};
