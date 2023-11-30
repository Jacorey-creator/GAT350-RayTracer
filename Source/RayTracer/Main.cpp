#include <string>
#include <iostream>
#include "Color.h"
#include "Random.h"
#include "Canvas.h"
#include "Renderer.h"

using namespace std;

int main(int, char**) 
{
	Renderer r;
	r.Initialize();
	r.CreateWindow("Cool", 400, 300);
	seedRandom((int)time(nullptr));
	Canvas canvas(400, 300, r);
	bool quit = false;
	while (!quit)
	{

		canvas.Clear({ 0, 0, 0, 1 });
		for (int i = 0; i < 1000; i++) canvas.DrawPoint({ random(0, canvas.GetSize().x), random(0, canvas.GetSize().y) }, { random(0, 1), random(0, 1), random(0, 1), 1 });
		canvas.Update();

		r.PresentCanvas(canvas);

		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}
	}
	r.Shutdown();
	
	/*string text = "Hello World";
	seedRandom(static_cast<unsigned int>(time(nullptr)));
	unsigned int intValue = 8888;
	color4_t colorFromUInt = ConvertUIntToColor(intValue);
	std::cout << "Color from unsigned int: (" << colorFromUInt.r << ", " << colorFromUInt.g << ", " << colorFromUInt.b << ", " << colorFromUInt.a << ")\n";
	std::cout << text;*/
	return 0;
}