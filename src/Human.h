	#include "RandomGenerator.h"
#include "Person.h"
#pragma once



class Human : public Person
{
private:

	int health;
	bool isSick;
	void update();
	void moveCase(int, int);
public:
	Human(int, bool, const Position&, int);
	void move();
};

