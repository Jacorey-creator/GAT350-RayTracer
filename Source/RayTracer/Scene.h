#pragma once
#include "Color.h"
#include "Ray.h"
#include <memory>
#include <vector>
#include "Camera.h"
#include "Object.h"
class Scene
{
public:
	Scene() = default;
	Scene(int depth = 5) : m_depth{ depth } {}
	Scene(const color3_t& topColor, const color3_t& bottomColor, int depth) :
		m_depth{ depth },
		m_topColor{ topColor },
		m_bottomColor{ bottomColor }
	{}
	void SetCamera(std::shared_ptr<Camera> camera) { m_camera = camera; }

	void Render(class Canvas& canvas, int numsamples, int m_depth);

	color3_t Trace(const ray_t& ray, float minDistance, float maxDistance, raycastHit_t& raycastHit, int depth);
	void AddObject(std::unique_ptr<class Object> object) { m_objects.push_back(std::move(object)); }
private:
	std::shared_ptr<Camera> m_camera;
	std::vector<std::unique_ptr<class Object>> m_objects;
	color3_t m_topColor{ 1 };
	color3_t m_bottomColor{ 0.5f };
	int m_depth{ 5 };
};