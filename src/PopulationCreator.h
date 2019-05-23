#include <iostream>
#include <vector>
#include "RandomGenerator.h"
#include "Person.h"
#include "Human.h"
#include "Doctor.h"
//#include "GraftingDoctor.h"

#pragma once



class PopulationCreator
{
private:
	std::vector<std::unique_ptr<Person>> people;
	void createPeople(int, int, int, int, int, const std::vector<Position>&);
public:
	PopulationCreator(int, int, int, int, int, const std::vector<Position>&);
	std::vector<std::unique_ptr<Person>> moveVector();
};

