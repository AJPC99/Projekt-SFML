#include "MapInterpreter.h"



MapInterpreter::MapInterpreter(const std::string& imageName)
{
	readMap(imageName);
}

void MapInterpreter::readMap(const std::string& imageName)
{
	image = std::make_unique<sf::Image>();
	image->loadFromFile(imageName);
	imageWidth = image->getSize().x;
	imageHeight = image->getSize().y;
	for (int i = 0; i < imageWidth; ++i)
	{
		for (int j = 0; j < imageHeight; ++j)
			if (image->getPixel(i, j).g == 255)
				lands.push_back(Position(i, j));
	}
}