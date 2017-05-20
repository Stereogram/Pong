#pragma once
#include <SFML/Window/Event.hpp>
#include <functional>
#include <unordered_map>


class EventMap
{
public:
	//each state should declare its own eventmap so the actions reference the correct state.
	EventMap() = default;
	void Register(sf::Event::EventType e, std::function<void(sf::Event&)> f) { _map[e] = f; }
	void Invoke(sf::Event& e)
	{
		if(_map.find(e.type) != _map.end())
			std::invoke(_map[e.type], e);
	}
	void Clear() { _map.clear(); }

	EventMap(const EventMap&) = delete;//delete copy constructor
	void operator=(const EventMap&) = delete;//delete assignment operator

private:
	
	std::unordered_map<sf::Event::EventType, std::function<void(sf::Event&)>,std::hash<sf::Event::EventType>> _map;
};
