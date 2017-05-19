#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Entity : public sf::Drawable
{
public:
	Entity();
	~Entity();
private:
	float _speed;
	sf::Vector2f _direction;
	sf::RectangleShape _shape;
};

