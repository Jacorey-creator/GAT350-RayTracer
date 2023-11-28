#include <string>
#include <sstream>
#include <iostream>
#include "Renderer.h"
using namespace std;

int main(int, char**) 
{
	Renderer* r = new Renderer;
	r->Initialize();
	r->CreateWindow("Cool", 400, 300);
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
	}
	SDL_Quit();
	r->Shutdown();
	
	string text = "Hello World";
	cout << text;
	return 0;
}