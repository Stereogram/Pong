#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "States/StateMachine.h"
#include "States/IntroState.h"

class Game
{
public:
	Game() = default;
	
	void run()
	{
		
		_window.create(sf::VideoMode{ 720, 480 }, "Pong", sf::Style::Titlebar | sf::Style::Close);

		// Initialize the engine
		_machine.run(std::move(std::make_unique<IntroState>(_machine, _window, true)));

		// Main loop
		while (_machine.running())
		{
			_machine.nextState();
			_machine.update();
			_machine.draw();
		}
	}

private:
	
	StateMachine _machine;
	sf::RenderWindow _window;
};
