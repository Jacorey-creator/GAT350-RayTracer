#pragma once

template<typename T>
inline T Lerp(const T& a, const T& b, float t)
{
	return lerp(a * (1.0f - t)) + (b * t);
}

template<typename T>
inline T Lerp(const T& a, const T& b, float t)
{
	return lerp(a, b, t) = (a * (1 - t)) + (t * b);
}