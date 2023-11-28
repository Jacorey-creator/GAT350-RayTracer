#pragma once
#include "glm/glm.hpp"

	struct ray_t
	{
		glm::vec3 origin;
		glm::vec3 direction;

		ray_t() = default;
		ray_t(const glm::vec3& origin, const glm::vec3& direction) :
			origin (origin),
			direction (direction)

			{}

		glm::vec3 GetPoint(float distance) const { return origin + (distance * direction); }

		//Overload Got help via ChatGpt
		glm::vec3 operator()(float distance) const {
			return GetPoint(distance);
		}

	};