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
#include "Triangle.h"


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
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 1, 15 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 20.0f, aspectRatio);

	Scene scene(glm::vec3{ 1.0f }, glm::vec3{ 0.5f, 0.7f, 1.0f }, 8);// sky color could be set with the top and bottom color
	scene.SetCamera(camera);
	auto material = std::make_shared<Lambertian>(color3_t{ 1, 0, 1 });
	auto lambertian = std::make_shared<Lambertian>(color3_t{ 0, 0, 1 });
	auto metal = std::make_shared<Metal>(color3_t{ 1, 1, 1 }, 0.0f);
	//// create objects -> add to scene
	//for (int i = 0; i < 10; i++)
	//{
	//	std::shared_ptr<Material> material = (rand() % 2 == 0) ? std::dynamic_pointer_cast<Material>(lambertian) : std::dynamic_pointer_cast<Material>(metal);
	//	auto sphere = std::make_unique<Sphere>(color3_t{ random(-1,2.5), random(), random() }, 1.0f, material);
	//	scene.AddObject(std::move(sphere));
	//}
	

	for (int x = -10; x < 10; x++)
	{
		for (int z = -10; z < 10; z++)
		{

			std::shared_ptr<Material> material;

			// create random material
			float r = random(0,1);
			if (r < 0.3f)		material = std::make_shared<Lambertian>(color3_t(glm::vec3{ random(0, 360), 1.0f, 1.0f }));
			else if (r < 0.6f)	material = std::make_shared<Metal>(color3_t{ random(0.5f, 1.0f) }, random(0, 0.5f));
			else if (r < 0.9f)	material = std::make_shared<Dielectric>(color3_t{ 1.0f }, random(1.1f, 2));
			else				material = std::make_shared<Emissive>(color3_t(glm::vec3{ random(0, 360), 1.0f, 1.0f }), 5.0f);
			
			// set random sphere radius
			float radius = random(0.2f, 0.3f);
			// create sphere using random radius and material
			auto sphere = std::make_unique<Sphere>(glm::vec3{ x + random(-0.5f, 0.5f), radius, z + random(-0.5f, 0.5f) }, radius, material);
			// add sphere to the scene
			scene.AddObject(std::move(sphere));
		}
	}
	auto triangle = std::make_unique<Triangle>(glm::vec3{ random(1, 10), random(1, 10), random(1, 10)}, glm::vec3{ random(1, 10), random(1, 10), random(1, 10)}, glm::vec3{ random(1, 10), random(1, 10), random(1, 10)}, metal);
	scene.AddObject(std::move(triangle));
	// Render scene 
	canvas.Clear({ 0, 0, 0, 1 });
	scene.Render(canvas, 10, 4);
	canvas.Update();

	while (!quit)
	{
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

		////CANVAS
		//canvas.Clear({ 0, 0, 0, 1 });
		////for (int i = 0; i < 1000; i++) canvas.DrawPoint({ random(0, canvas.GetSize().x), random(0, canvas.GetSize().y) }, { random(0, 1), random(0, 1), random(0, 1), 1 });
		//scene.Render(canvas);
		//canvas.Update();
		r.PresentCanvas(canvas);

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