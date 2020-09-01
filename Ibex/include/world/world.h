#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <utility>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "../mesh/mesh.h"
#include "../mesh/grid.h"
#include "../lighting/lighting.h"

struct CameraConfig {
	glm::vec3 origin;
	Camera instance;
};

struct WorldConfig {
	bool showGrid;
	double gridSize;
	glm::vec3 origin;
	std::pair<glm::vec3, glm::vec3> bounds;
	glm::vec4 backgroundColor;
	glm::vec4 foregroundColor;
	glm::vec4 gridColor;
};

struct LightingConfig {
	float ambientStrength;
	const char* vertexPath;
	const char* fragmentPath;
};

struct WindowConfig {
	std::pair<int, int> dim;
};

class World {
public:
	WorldConfig world;
	CameraConfig camera;
	LightingConfig lighting;
	WindowConfig window;

	Shader meshShader;

	std::vector<Mesh*> elements;

	std::vector<Lighting*> lightSources;

	Grid* grid;

	World();
	World(WorldConfig, CameraConfig, LightingConfig, WindowConfig);

	virtual int load();
	virtual int onTick();
	virtual int cleanup();

	virtual int setWorld(WorldConfig);
	virtual int setCamera(CameraConfig);
	virtual int setLighting(LightingConfig);
	virtual int setWindow(WindowConfig);

	template <typename ET, typename... PT>
	int addElement(PT... parameters) {
		// Heap allocation using new to outlive this block
		Mesh* element = new ET(parameters...);
		elements.push_back(element);
		return 0;
	}

	template <typename LT, typename... PT>
	int addLighting(PT... parameters) {
		// Heap allocation using new to outlive this block
		Lighting* lightSource = new LT(parameters...);
		lightSources.push_back(lightSource);
		return 0;
	}
};

#endif
