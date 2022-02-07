#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <camera/camera.h>
#include <mesh/mesh.h>
#include <mesh/grid.h>
#include <lighting/lighting.h>

struct WindowOptions {
	std::pair<unsigned int, unsigned int> dim;
};

struct WorldOptions {
	glm::vec4 backgroundColor;
	glm::vec4 foregroundColor;
	glm::vec4 wireframeColor;
	std::pair<glm::vec3, glm::vec3> bounds;
};

struct GridOptions {
	int gridSize;
	glm::vec4 gridColor;
};

class World {
protected:
	// Global options set during construction.
	WindowOptions windowOptions;
	WorldOptions worldOptions;
	GridOptions gridOptions;

	// Wireframe
	bool showWireframe;

	// Grid variables
	std::unique_ptr<Grid> grid;

	std::vector<std::shared_ptr<Camera>> cameras;
	std::vector<std::shared_ptr<Mesh>> elements;
	std::vector<std::shared_ptr<Lighting>> lightSources;
	std::shared_ptr<Camera> activeCamera;

	template <typename CT = Camera, typename... PT>
	int addCamera(PT&&... parameters) {
		std::shared_ptr<Camera> camera = std::make_shared<CT>(std::forward<PT>(parameters)...);
		cameras.emplace_back(camera);
		activeCamera = camera;
		return 0;
	}

	template <typename ET = Mesh, typename... PT>
	int addElement(PT&&... parameters) {
		std::shared_ptr<Mesh> element = std::make_shared<ET>(std::forward<PT>(parameters)...);
		elements.emplace_back(element);
		return 0;
	}

	template <typename LT = Lighting, typename... PT>
	int addLighting(PT&&... parameters) {
		std::shared_ptr<Lighting> lightSource = std::make_shared<LT>(std::forward<PT>(parameters)...);
		lightSources.emplace_back(lightSource);
		return 0;
	}

public:
	World();
	World(WindowOptions, WorldOptions, GridOptions);

	// Every world *must* implement their own independent load, tick and cleanup methods.
	virtual int load() = 0;
	virtual int onTick() = 0;
	virtual int cleanup() = 0;

	int setWindowDim(unsigned int, unsigned int);
	int toggleWireframe();

	std::shared_ptr<Camera>& getActiveCamera();
	WindowOptions getWindowOptions();
	WorldOptions getWorldOptions();
};

#endif
