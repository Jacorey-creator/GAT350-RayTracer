#include <string>
#include <iostream>
#include "Color.h"
#include "Random.h"
#include "Canvas.h"
#include "Renderer.h"
#include "Material.h"
#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"

using namespace std;

int main(int, char**)
{
	Renderer r;
	r.Initialize();
	r.CreateWindow("Cool", 400, 300);
	seedRandom((int)time(nullptr));
	Canvas canvas(400, 300, r);
	bool quit = false;
	//SCENE
	float aspectRatio = canvas.GetSize().x / (float)canvas.GetSize().y;
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 0, 1 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 70.0f, aspectRatio);

	Scene scene; // sky color could be set with the top and bottom color
	scene.SetCamera(camera);
	while (!quit)
	{
		//CANVAS
		canvas.Clear({ 0, 0, 0, 1 });
		for (int i = 0; i < 1000; i++) canvas.DrawPoint({ random(0, canvas.GetSize().x), random(0, canvas.GetSize().y) }, { random(0, 1), random(0, 1), random(0, 1), 1 });
		canvas.Update();
		canvas.Clear({ 0, 0, 0, 1 });
		scene.Render(canvas);
		canvas.Update();
		// create objects -> add to scene
		auto sphere = std::make_unique<Sphere>(glm::vec3{ 12, 12, 24 }, 6, std::make_unique<Material>());
		scene.AddObject(sphere);
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

	string text = "Hello World";
	seedRandom(static_cast<unsigned int>(time(nullptr)));
	unsigned int intValue = 8888;
	color4_t colorFromUInt = ConvertUIntToColor(intValue);
	std::cout << "Color from unsigned int: (" << colorFromUInt.r << ", " << colorFromUInt.g << ", " << colorFromUInt.b << ", " << colorFromUInt.a << ")\n";
	std::cout << text;
	return 0;
}