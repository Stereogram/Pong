#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "States/StateMachine.h"
#include "States/IntroState.h"

class Game
{
public:
	Game()
	{
		_window.create(sf::VideoMode{ 720, 480 }, "Pong", sf::Style::Titlebar | sf::Style::Close);

		_machine.run(std::make_unique<IntroState>(_machine, _window, true));
	}
	
	void run()
	{
		sf::Clock timer;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;

		while (_machine.running())
		{
			_machine.nextState();
			sf::Time dt = timer.getElapsedTime();
			timer.restart();
			timeSinceLastUpdate += dt;
			while (timeSinceLastUpdate > _timePerFrame)
			{
				timeSinceLastUpdate -= _timePerFrame;
				_machine.update(_timePerFrame);
			}
			_machine.draw();
		}
	}

private:
	const sf::Time _timePerFrame = sf::seconds(1.0f / 60.0f);
	StateMachine _machine;
	sf::RenderWindow _window;
};
