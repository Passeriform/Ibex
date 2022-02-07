#include "world.h"

World::World() :
	windowOptions({ std::make_pair(1024, 1024) }),
	worldOptions(
		{
			glm::vec4(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f),			// backgroundColor
			glm::vec4(0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f),		// foregroundColor
			glm::vec4(0.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f, 1.0f),		// wireframeColor
			std::make_pair(															// bounds
				glm::vec3(-1000.0f, -1000.0f, -1000.0f),
				glm::vec3(1000.0f, 1000.0f, 1000.0f)
			),
		}
	),
	gridOptions({ 32, glm::vec4(0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f) })
{ }

World::World(WindowOptions windowOptions, WorldOptions worldOptions, GridOptions gridOptions) :
	windowOptions(windowOptions),
	worldOptions(worldOptions),
	gridOptions(gridOptions)
{ }

int World::setWindowDim(unsigned int width, unsigned int height) {
	this->windowOptions.dim = std::make_pair(width, height);
	return 0;
}

int World::toggleWireframe() {
	this->showWireframe = !showWireframe;
	return 0;
}

std::shared_ptr<Camera>& World::getActiveCamera() {
	if (!activeCamera) return cameras[0];
	return activeCamera;
}

WorldOptions World::getWorldOptions() {
	return this->worldOptions;
}

WindowOptions World::getWindowOptions() {
	return this->windowOptions;
}