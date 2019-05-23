#include "MapDrawer.h"



MapDrawer::MapDrawer(const std::string& imageName, int turnDelay, int humanHealth, int numberOfHumans,
	int numberOfSickHumans,int numberOfDoctors) : MapInterpreter(imageName)
{
	PopulationCreator p(humanHealth, numberOfHumans, numberOfSickHumans, numberOfDoctors, 0, lands);
	people = p.moveVector();

	for (int i = 0; i < people.size(); ++i)
		people[i]->setImage(image);

	window.create(sf::VideoMode(imageWidth, imageHeight), "Simulation");
	texture.loadFromImage(*image);
	sprite.setTexture(texture);
	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Sleep(turnDelay);
		updatePeople();
		updateTexture();
		window.clear();
		drawImage();
		window.display();
	}
}
void MapDrawer::updatePeople()
{
	for (int i = 0; i < people.size(); ++i)
		people[i]->move();
}
void MapDrawer::updateTexture()
{
	texture.loadFromImage(*image);
}

void MapDrawer::drawImage()
{
	window.draw(sprite);
}