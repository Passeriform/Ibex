#include <lighting/omni_direction_light.h>
#include <model/model.h>
#include <mesh/primitives/cube.h>
#include <material/material.h>

#include "void.h"

Void::Void() : World() {
	// World config setup
	world.backgroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	world.foregroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	world.gridColor = glm::vec4(137.0f / 255.0f, 23.0f / 255.0f, 135.0f / 255.0f, 1.0f);

	// Camera config setup
	camera.origin = glm::vec3(0.0f, 1.0f, 3.0f);
	camera.instance = Camera(camera.origin);

	// Load model
	// std::string path = "resources/models/crisis.assimp";
	// this->addElement<Model>(Model(path));

	// Add all mesh elements
	this->addElement<Cube>(new Material(
		MATERIAL_REGISTRY[MaterialType::EMERALD],
		{
			new Texture("resources/textures/wooden_box.png"),
			new Texture("resources/textures/wooden_box_specular.png"),
		}
	));		// Loading Emerald material with container texture over a Cube mesh

	// Add lights after mesh elements for consistency
	this->addLighting<OmniDirectionLight>(
		glm::vec3(0.8f, 1.4f, 2.0f),		// Origin
		glm::vec3(1.0f, 1.0f, 1.0f),		// Light Color
		glm::vec3(0.2f),				// Ambient Factor
		glm::vec3(0.5f),				// Diffuse Factor
		glm::vec3(1.0f)					// Specular Factor
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
	meshShader = Shader("shaders/materialShader.vert", "shaders/materialShader.frag");
	gridShader = Shader("shaders/gridShader.vert", "shaders/gridShader.frag");

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

	// Setting up model, view and projection matrices
	glm::mat4 projection = glm::perspective(glm::radians(camera.instance.Zoom), (float)window.dim.first / (float)window.dim.second, 0.1f, 100.0f);
	glm::mat4 view = camera.instance.GetViewMatrix();
	glm::mat4 model = glm::mat4(1.0f);

	// Draw grid
	if (world.showGrid) {
		// Using grid shaders
		gridShader.use();

		// Set lighting-based uniforms per pixel per draw cycle
		gridShader.setVec3("viewPos", camera.instance.Position);

		// Setting model, view and projection matrices in the shader
		gridShader.setMat4("model", model);
		gridShader.setMat4("view", view);
		gridShader.setMat4("projection", projection);

		grid->draw();
	}

	// Using mesh shaders
	meshShader.use();

	// Set lighting-based uniforms per pixel per draw cycle
	meshShader.setVec3("viewPos", camera.instance.Position);

	// Setting model, view and projection matrices in the shader
	meshShader.setMat4("model", model);
	meshShader.setMat4("view", view);
	meshShader.setMat4("projection", projection);

	// Draw all elements
	for (auto element : elements) {
		MaterialLightMap lightMap = element->material->materialLightMap;
		// Set material parameters per element
		meshShader.setVec3("material.ambient", lightMap.ambient);		// Add ambient strength to shader

		// Set offset layout pointer for registered textures
		if (element->material->isTextured()) {
			meshShader.setInt("material.diffuse", 0);
			meshShader.setInt("material.specular", 1);
		}
		// Add explicit diffuse and specular strengths to shader
		else {
			meshShader.setVec3("material.diffuse", lightMap.diffuse);
			meshShader.setVec3("material.specular", lightMap.specular);
		}

		meshShader.setFloat("material.shininess", lightMap.shininess);	// Add shininess to shader

		element->draw();
	}

	// Draw all light sources
	for (auto light : lightSources) {
		// Sending lighting parameters to mesh shader
		meshShader.setVec3("light.position", light->getPosition());
		meshShader.setVec3("light.ambient", light->getAmbientColor());
		meshShader.setVec3("light.diffuse", light->getDiffuseColor());
		meshShader.setVec3("light.specular", light->getSpecularColor());

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
