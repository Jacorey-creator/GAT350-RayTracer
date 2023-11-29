#include <string>
#include <sstream>
#include <iostream>
#include "Renderer.h"
#include "Color.h"

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
	unsigned int intValue = 8888;
	color4_t colorFromUInt = ConvertUIntToColor(intValue);
	std::cout << "Color from unsigned int: (" << colorFromUInt.r << ", " << colorFromUInt.g << ", " << colorFromUInt.b << ", " << colorFromUInt.a << ")\n";
	cout << text;
	return 0;
}