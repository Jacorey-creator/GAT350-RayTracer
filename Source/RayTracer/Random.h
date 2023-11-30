#pragma once
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <random>

void seedRandom(unsigned int seed)
{
	srand(seed);
}

float random() 
{
	return static_cast<float>(rand()) / RAND_MAX;
}

float random(float min, float max)
{
	if (min > max)
	{
		std::swap(min, max);
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> distribution(min, max);

	return distribution(gen);
}