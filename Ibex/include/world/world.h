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

struct CameraConfig {
	glm::vec3 origin;
	Camera instance;
};

struct ShaderConfig {
	const char* worldVertexShader, * worldFragmentShader;
	Shader worldShader;
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

struct WindowConfig {
	std::pair<int, int> dim;
};

class World {
public:
	WorldConfig world;
	CameraConfig camera;
	ShaderConfig shader;
	WindowConfig window;

	World();
	World(WorldConfig, CameraConfig, ShaderConfig, WindowConfig);

	virtual int load();
	virtual int onTick();
	virtual int cleanup();

	virtual int setWorld(WorldConfig);
	virtual int setCamera(CameraConfig);
	virtual int setShader(ShaderConfig);
	virtual int setWindow(WindowConfig);

	template <typename CT>
	int addElement() {
		// Heap allocation using new to outlive this block
		Mesh* component = new CT();
		elements.push_back(component);
		return 0;
	}
};

#endif
