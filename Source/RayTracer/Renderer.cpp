#include "Renderer.h"

bool Renderer::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "SDL ERROR: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void Renderer::Shutdown()
{
	m_window != nullptr ? SDL_DestroyWindow(m_window) : SDL_Quit();

	m_renderer != nullptr ? SDL_DestroyRenderer(m_renderer) : SDL_Quit();
}

bool Renderer::CreateWindow(const std::string& title, int width, int height)
{
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (!m_window) 
	{
		std::cerr << "SDL: ERROR WINDOW" << SDL_GetError() << std::endl;
		return false;
	}
	
	m_renderer = SDL_CreateRenderer(m_window, 0 ,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_renderer)
	{
		std::cerr << "SDL: ERROR RENDER" << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}