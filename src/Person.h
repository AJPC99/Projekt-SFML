#include <SFML/Graphics.hpp>
#include <memory>
#include "RandomGenerator.h"
#include "RandomGenerator.h"
#include "Position.h"
#pragma once



class Person
{
protected:
	bool isAlive;
	Position position;
	sf::Color color;
	std::shared_ptr<sf::Image> image;
	RandomGenerator r;
	Person(const Position&, int);
public:
	void setImage(std::shared_ptr<sf::Image>&);
	virtual void move() = 0;
};
