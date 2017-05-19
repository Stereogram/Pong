﻿#pragma once
#include <stack>
#include <memory>
#include "State.h"

class StateMachine
{
public:
	StateMachine() = default;
	void run(std::unique_ptr<State> state) { _running = true; _states.push(std::move(state)); }

	void nextState();
	void lastState() { _resume = true; }
	void update() const { _states.top()->update(); }
	void draw() const { _states.top()->draw(); }

	bool running() const { return _running; }
	void quit() { _running = false; }

private:
	bool _resume = false;
	bool _running = false;
	std::stack<std::unique_ptr<State>> _states;
};
