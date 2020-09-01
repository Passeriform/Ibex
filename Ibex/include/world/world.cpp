#include "world.h"

World::World() {
	world = WorldConfig{
		true,                                                                   // showGrid
		32,                                                                     // gridSize
		glm::vec3(0.0f, 0.0f, 0.0f),                                            // origin
		std::make_pair(                                                         // bounds
			glm::vec3(-1000.0f, -1000.0f, -1000.0f),
			glm::vec3(1000.0f, 1000.0f, 1000.0f)
		),
		glm::vec4(0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f),           // backgroundColor
		glm::vec4(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f),     // foregroundColor
		glm::vec4(127.0f / 255.0f, 127.0f / 255.0f, 127.0f / 255.0f, 1.0f)      // gridColor
	};

	camera = CameraConfig{
		glm::vec3(0.0f, 0.0f, 0.0f)                 // origin
	};

	shader = ShaderConfig{                          // Shaders remain uninitialized
	};

	window = WindowConfig{                          // Window remains uninitialized
	};
}

World::World(WorldConfig world, CameraConfig camera, ShaderConfig shader, WindowConfig window) :
	world(world),
	camera(camera),
	shader(shader),
	window(window)
{ }

int World::load() {
	return 0;
}

int World::onTick() {
	return 0;
}

int World::cleanup() {
	return 0;
}

int World::setWorld(WorldConfig world) {
	this->world = world;
	return 0;
}

int World::setCamera(CameraConfig camera) {
	this->camera = camera;
	return 0;
}

int World::setShader(ShaderConfig shader) {
	this->shader = shader;
	return 0;
}

int World::setWindow(WindowConfig window) {
	this->window = window;
	return 0;
}
