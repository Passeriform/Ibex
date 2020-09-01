#include "void.h"

Void::Void() : World() {
	world.backgroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	world.foregroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	world.gridColor = glm::vec4(137.0f / 255.0f, 23.0f / 255.0f, 135.0f / 255.0f, 1.0f);

	camera.origin = glm::vec3(0.0f, 1.0f, 3.0f);
	camera.instance = Camera(camera.origin);

	shader.worldVertexShader = "shaders/meshShader.vert";
	shader.worldFragmentShader = "shaders/meshShader.frag";

	this->addElement<Triangle>();
};

Void::Void(WorldConfig world, CameraConfig camera, ShaderConfig shader, WindowConfig window) :
	World(world, camera, shader, window) {
	camera.instance = Camera(camera.origin);
};

int Void::load() {
	// Initialize the grid buffers
	grid = new Grid(window.dim, world.gridSize, world.gridColor);

	// Shader must be created only after GLAD is loaded by engine
	shader.worldShader = Shader(shader.worldVertexShader, shader.worldFragmentShader);

	for (auto element : elements) {
		element->setupBuffers();
	}

	grid->setupBuffers();

	return 0;
}

int Void::onTick() {
	// Paint background color
	glClearColor(
		world.backgroundColor[0],
		world.backgroundColor[1],
		world.backgroundColor[2],
		world.backgroundColor[3]
	);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader.worldShader.use();

	glm::mat4 projection = glm::perspective(glm::radians(camera.instance.Zoom), (float)window.dim.first / (float)window.dim.second, 0.1f, 100.0f);
	shader.worldShader.setMat4("projection", projection);

	glm::mat4 view = camera.instance.GetViewMatrix();
	shader.worldShader.setMat4("view", view);

	glm::mat4 model = glm::mat4(1.0f);
	shader.worldShader.setMat4("model", model);

	for (auto element : elements) {
		element->draw();
	}

	if (world.showGrid) grid->draw();

	return 0;
}

int Void::cleanup() {
	// Flush buffer
	for (auto element : elements) {
		element->deleteBuffers();
	}

	grid->deleteBuffers();

	return 0;
}
