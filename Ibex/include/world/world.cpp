#include "world.h"
#include "camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

World::World() {
	world.origin = glm::vec3(0.0f, 0.0f, 0.0f);
	world.bounds = { glm::vec3(-1000.0f, -1000.0f, -1000.0f), glm::vec3(1000.0f, 1000.0f, 1000.0f) };
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

int World::setWindowDim(std::pair<int, int> scrDim)
{
	window.dim = scrDim;
	return 0;
}
