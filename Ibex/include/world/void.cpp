#include "void.h"
#include "mesh/primitives/cube.h"
#include "lighting/omniDirectionLight.h"

Void::Void() : World() {
	world.backgroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	world.foregroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	world.gridColor = glm::vec4(137.0f / 255.0f, 23.0f / 255.0f, 135.0f / 255.0f, 1.0f);

	camera.origin = glm::vec3(0.0f, 1.0f, 3.0f);
	camera.instance = Camera(camera.origin);

	this->addElement<Cube>();

	this->addLighting<OmniDirectionLight>(
		glm::vec3(0.6f, 0.0f, 0.8f),		// Origin
		glm::vec3(1.0f, 1.0f, 1.0f)			// Light Color
		);
};

Void::Void(WorldConfig world, CameraConfig camera, LightingConfig lighting, WindowConfig window) :
	World(world, camera, lighting, window) {
	camera.instance = Camera(camera.origin);
};

int Void::load() {
	// Initialize the grid buffers
	grid = new Grid(window.dim, world.gridSize, world.gridColor);

	// Shader must be created only after GLAD is loaded by engine
	meshShader = Shader("shaders/meshShader.vert", "shaders/meshShader.frag");

	grid->setupBuffers();

	for (auto element : elements) {
		element->setupBuffers();
	}

	for (auto light : lightSources) {
		light->setupShaders();
	}

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

	meshShader.use();

	// Set shader uniforms per pixel per draw cycle
	meshShader.setVec3("viewPos", camera.instance.Position);
	meshShader.setVec3("lightPos", lightSources[0]->getPosition());		// Must run for all light sources (Testing with one).
	meshShader.setVec3("lightColor", lightSources[0]->getColor());		// Must run for all light sources (Testing with one).

	glm::mat4 projection = glm::perspective(glm::radians(camera.instance.Zoom), (float)window.dim.first / (float)window.dim.second, 0.1f, 100.0f);
	meshShader.setMat4("projection", projection);

	glm::mat4 view = camera.instance.GetViewMatrix();
	meshShader.setMat4("view", view);

	glm::mat4 model = glm::mat4(1.0f);
	meshShader.setMat4("model", model);

	if (world.showGrid) grid->draw();

	for (auto element : elements) {
		meshShader.setFloat("ambientStrength", lighting.ambientStrength);	// Add ambient strength to shader
		meshShader.setFloat("specularStrength", lighting.specularStrength);	// Add specular strength to shader
		meshShader.setFloat("shininess", lighting.shininess);				// Add shininess to shader

		element->draw();
	}

	for (auto light : lightSources) {
		light->draw(&camera.instance, window.dim);
	}

	return 0;
}

int Void::cleanup() {
	grid->deleteBuffers();

	for (auto element : elements) {
		element->deleteBuffers();
	}

	for (auto light : lightSources) {
		light->deleteShadersAndBuffers();
	}

	return 0;
}
