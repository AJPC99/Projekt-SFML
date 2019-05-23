	#include "RandomGenerator.h"
#include "Person.h"
#pragma once



class Doctor : public Person
{
private:
	void moveCase(int, int);
public:
	Doctor(const Position&, int);
	void move();
};
