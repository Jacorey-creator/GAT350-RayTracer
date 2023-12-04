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

inline glm::vec3 random(const glm::vec3& min, const glm::vec3& max)
{
	float t = random(0.0f, 1.0f);  // Generates a random value between 0 and 1
	glm::vec3 resultVector = glm::mix(min, max, t);
}

inline glm::vec3 randomInUnitSphere()
{
	glm::vec3 v;
	// generate random vectors between -1 <-> +1, return vector if length is less than 1
	do
	{
		v = random(glm::vec3{ (-1, -1, -1) }, glm::vec3{(1, 1, 1)});
	} while (glm::length(v) >= 1.0f);

		return v;
}