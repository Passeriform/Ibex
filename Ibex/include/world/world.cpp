#include "world.h"

World::World() {
	world = WorldConfig{
		true,							// showGrid
		32,								// gridSize
		glm::vec3(0.0f, 0.0f, 0.0f),	// origin
		std::make_pair(					// bounds
			glm::vec3(-1000.0f, -1000.0f, -1000.0f),
			glm::vec3(1000.0f, 1000.0f, 1000.0f)
		),

		glm::vec4(0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f),			// backgroundColor
		glm::vec4(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f),		// foregroundColor
		glm::vec4(127.0f / 255.0f, 127.0f / 255.0f, 127.0f / 255.0f, 1.0f)		// gridColor
	};

	camera = CameraConfig{
		glm::vec3(0.0f, 0.0f, 0.0f)		// origin
	};

	lighting = LightingConfig{
		"shaders/lightShader.vert",					// vertexPath
		"shaders/lightShader.frag"					// fragmentPath
	};												// TODO: Provision for adding multiple selectable lighting shader.

	window = WindowConfig{							// Window remains uninitialized (Must be initialized within world loading.
	};
}

World::World(WorldConfig world, CameraConfig camera, LightingConfig lighting, WindowConfig window) :
	world(world),
	camera(camera),
	lighting(lighting),
	window(window)
{ }

int World::setWorld(WorldConfig world) {
	this->world = world;
	return 0;
}

int World::setCamera(CameraConfig camera) {
	this->camera = camera;
	return 0;
}

int World::setLighting(LightingConfig lighting) {
	this->lighting = lighting;
	return 0;
}

int World::setWindow(WindowConfig window) {
	this->window = window;
	return 0;
}
