#include "Human.h"



Human::Human(int health, bool isSick, const Position& position, int rand)
	: Person(position, rand)
{
	this->health = health;
	this->isSick = isSick;
	if (isSick)
	{
		color = sf::Color::Red;
	}
	else
	{
		color = sf::Color::White;
	}
}

void Human::update()
{
	if (image->getPixel(position.x, position.y) == sf::Color::Red && !isSick)
	{
		isSick = true;
	}
	else if (isSick && image->getPixel(position.x, position.y) == sf::Color::White)
	{
		isSick = false;
	}

	if (isSick)
	{
		health--;
	}
	if (health <= 0)
	{
		if (isAlive)
		{
			isAlive = false;
			image->setPixel(position.x, position.y, sf::Color::Green);
		}
	}
}

void Human::moveCase(int x, int y)
{
	sf::Vector2u imageSize = image->getSize();
	if ((position.x + x >= 0 && position.x + x <= imageSize.x)
		&& (position.y + y >= 0 && position.y + y <= imageSize.y) && isAlive)
	{
		if (isSick)
		{
			if (image->getPixel(position.x + x, position.y + y).g == 255)
			{
				image->setPixel(position.x, position.y, sf::Color::Green);
				position.x += x;
				position.y += y;
				image->setPixel(position.x, position.y, sf::Color::Red);
			}
			else if (image->getPixel(position.x + x, position.y + y) == sf::Color::White)
			{
				image->setPixel(position.x + x, position.y + y, sf::Color::Red);
			}
		}
		else if (image->getPixel(position.x + x, position.y + y).g == 255)
		{
			image->setPixel(position.x, position.y, sf::Color::Green);
			position.x += x;
			position.y += y;
			image->setPixel(position.x, position.y, sf::Color::White);
		}
	}

}

void Human::move()
{
	update();
	switch (r.random())
	{
	case 0:
		moveCase(1, 0);
		break;
	case 1:
		moveCase(1, 1);
		break;
	case 2:
		moveCase(1, -1);
		break;
	case 3:
		moveCase(0, 1);
		break;
	case 4:
		moveCase(0, -1);
		break;
	case 5:
		moveCase(-1, 1);
		break;
	case 6:
		moveCase(-1, 0);
		break;
	case 7:
		moveCase(-1, -1);
		break;
	}
}
