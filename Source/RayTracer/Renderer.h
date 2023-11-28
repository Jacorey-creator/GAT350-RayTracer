#pragma once
#include <string>
#include "SDL.h"
#include <iostream>


class Renderer
{
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();
	bool CreateWindow(const std::string& title, int width, int height);
private:
	SDL_Renderer* m_renderer = nullptr;
	SDL_Window* m_window = nullptr;
};