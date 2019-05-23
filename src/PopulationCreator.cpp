#include "PopulationCreator.h"



PopulationCreator::PopulationCreator(int healthOfHumans, int numberOfHumans,
	int numberOfSickHumans, int numberOfDoctors,
	int numberOfGraftingDoctors, const std::vector<Position>& lands)
{
	createPeople(healthOfHumans, numberOfHumans, numberOfSickHumans,
		numberOfDoctors, numberOfGraftingDoctors, lands);
}

void PopulationCreator::createPeople(int healthOfHumans,
	int numberOfHumans, int numberOfSickHumans,
	int numberOfDoctors, int numberOfGraftingDoctors, const std::vector<Position>& lands)
{
	RandomGenerator rand(lands.size(), 324);
	std::vector<bool> isPerson(lands.size());
	for (auto i : isPerson)
		isPerson[i] = false;
	people.resize(numberOfHumans + numberOfSickHumans
		+ numberOfDoctors + numberOfGraftingDoctors);
	int i = 0;
	int temp;
	for (i; i < numberOfSickHumans; ++i)
	{
		temp = rand.random();
		while (isPerson[temp] == true)
			temp = rand.random();
		people[i] = std::make_unique<Human>(healthOfHumans, true, Position(lands[temp]), rand.random());
		isPerson[temp] = true;
	}
	for (i; i < numberOfHumans + numberOfSickHumans; ++i)
	{
		temp = rand.random();
		while (isPerson[temp] == true)
			temp = rand.random();
		people[i] = std::make_unique<Human>(healthOfHumans, false, Position(lands[temp]), rand.random());
		isPerson[temp] = true;
	}
		for (i; i < numberOfDoctors + numberOfHumans + numberOfSickHumans; ++i)
		{
			temp = rand.random();
			while (isPerson[temp] == true)
				temp = rand.random();
			people[i] = std::make_unique<Doctor>(Position(lands[temp]), rand.random());
			isPerson[temp] = true;
		}
	/*	for (i; i < numberOfDoctors + numberOfHumans +
			numberOfGraftingDoctors + numberOfSickHumans; ++i)
		{
			temp = rand.random();
			while (isPerson[temp] == true)
				temp = rand.random();
			people[i] = std::make_unique<GraftingDoctor>(Position(lands[temp]), i);
			isPerson[temp] = true;
		}*/
}

std::vector<std::unique_ptr<Person>> PopulationCreator::moveVector()
{
	return std::move(people);
}