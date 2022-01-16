#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <utility>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader/shader.h>
#include <camera/camera.h>
#include <mesh/mesh.h>
#include <mesh/grid.h>
#include <lighting/lighting.h>

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
	const char* vertexPath;
	const char* fragmentPath;
};

struct WindowConfig {
	std::pair<int, int> dim;
};

class World {
	LightingConfig lighting;

protected:
	WorldConfig world;
	WindowConfig window;
	Grid* grid;

	Shader meshShader;
	Shader gridShader;

	std::vector<Mesh*> elements;

	std::vector<Lighting*> lightSources;

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

public:
	CameraConfig camera;

	World();
	World(WorldConfig, CameraConfig, LightingConfig, WindowConfig);

	// Every world *must* implement their own independent load, tick and cleanup methods.
	virtual int load() = 0;
	virtual int onTick() = 0;
	virtual int cleanup() = 0;

	virtual int setWorld(WorldConfig);
	virtual int setCamera(CameraConfig);
	virtual int setLighting(LightingConfig);
	virtual int setWindow(WindowConfig);
};

#endif
