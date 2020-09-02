#include "void.h"
#include "lighting/omniDirectionLight.h"
#include "mesh/primitives/cube.h"
#include "material/emerald.h"

Void::Void() : World() {
	// World config setup
	world.backgroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	world.foregroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	world.gridColor = glm::vec4(137.0f / 255.0f, 23.0f / 255.0f, 135.0f / 255.0f, 1.0f);

	// Camera config setup
	camera.origin = glm::vec3(0.0f, 1.0f, 3.0f);
	camera.instance = Camera(camera.origin);

	// Add all mesh elements
	this->addElement<Cube>(new Emerald());		// Loading Gold material over a Cube mesh

	// Add lights after mesh elements for consistency
	this->addLighting<OmniDirectionLight>(
		glm::vec3(0.8f, 1.4f, 2.0f),		// Origin
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

	// Setup grid buffers
	grid->setupBuffers();

	// Setup all element buffers
	for (auto element : elements) {
		element->setupBuffers();
	}

	// Setup all light source buffers
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

	// Clearing color and depth buffer each cycle
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	meshShader.use();

	// Set lighting-based uniforms per pixel per draw cycle
	meshShader.setVec3("viewPos", camera.instance.Position);

	// Sending lighting parameters to mesh shader
	// Must run for all light sources (Testing with one)
	meshShader.setVec3("light.position", lightSources[0]->getPosition());
	meshShader.setVec3("light.ambient", lightSources[0]->getAmbientColor());
	meshShader.setVec3("light.diffuse", lightSources[0]->getDiffuseColor());
	meshShader.setVec3("light.specular", lightSources[0]->getSpecularColor());

	// Setting up model, view and projection matrices
	glm::mat4 projection = glm::perspective(glm::radians(camera.instance.Zoom), (float)window.dim.first / (float)window.dim.second, 0.1f, 100.0f);
	glm::mat4 view = camera.instance.GetViewMatrix();
	glm::mat4 model = glm::mat4(1.0f);

	// Setting model, view and projection matrices in the shader
	meshShader.setMat4("model", model);
	meshShader.setMat4("view", view);
	meshShader.setMat4("projection", projection);

	// Draw grid first to minimize the shader swap
	if (world.showGrid) grid->draw();

	// Draw all elements
	for (auto element : elements) {
		// Set material parameters per element
		meshShader.setVec3("material.ambient", element->material->ambient);	// Add ambient strength to shader
		meshShader.setVec3("material.diffuse", element->material->diffuse);	// Add diffuse strength to shader
		meshShader.setVec3("material.specular", element->material->specular);	// Add specular strength to shader
		meshShader.setFloat("material.shininess", element->material->shininess);		// Add shininess to shader

		element->draw();
	}

	// Draw all light sources
	for (auto light : lightSources) {
		light->draw(&camera.instance, window.dim);
	}

	return 0;
}

int Void::cleanup() {
	// Clear grid buffers
	grid->deleteBuffers();

	// Clear all element buffers
	for (auto element : elements) {
		element->deleteBuffers();
	}

	// Clear all light source buffers
	for (auto light : lightSources) {
		light->deleteShadersAndBuffers();
	}

	return 0;
}
