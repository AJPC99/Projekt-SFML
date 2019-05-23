#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Position.h"
#pragma once



class MapInterpreter
{
private:
	void readMap(const std::string&);
protected:
	int imageWidth;
	int imageHeight;
	std::vector<Position> lands;
	std::shared_ptr<sf::Image> image;
public:
	explicit MapInterpreter(const std::string&);
};

