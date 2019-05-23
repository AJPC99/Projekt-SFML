#include <random>
#pragma once



class RandomGenerator
{
private:
	std::random_device dev;
	typedef std::mt19937 MyRng;
	MyRng rng;
	std::uniform_int_distribution<int> number;
public:
	RandomGenerator(int, int);
	int random();
};

