#include "RandomGenerator.h"



RandomGenerator::RandomGenerator(int MR, int rand) : rng(dev()), number(std::uniform_int_distribution<>(1, MR + 1))
{
	rng.seed(rand);
}

int RandomGenerator::random()
{
	return number(rng) - 1;
}

