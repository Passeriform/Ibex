#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <utility>

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
	char* worldVertexShader, * worldFragmentShader;
	Shader worldShader;
};

struct WorldConfig {
	glm::vec3 origin;
	std::pair<glm::vec3, glm::vec3> bounds;
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
	virtual int setWindowDim(std::pair<int, int>);
};

#endif