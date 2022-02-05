#include <memory>

#include <lighting/omni_direction_light.h>
#include <model/model.h>
#include <mesh/primitives/cube.h>
#include <material/material.h>

#include "void.h"

Void::Void() : World() {
	/* Setup static world options */
	worldOptions.backgroundColor = glm::vec4(2.0f / 255.0f, 0.0f / 255.0f, 10.0f / 255.0f, 1.0f);
	worldOptions.foregroundColor = glm::vec4(42.0f / 255.0f, 0.0f / 255.0f, 41.0f / 255.0f, 1.0f);
	gridOptions.gridColor = glm::vec4(212.0f / 255.0f, 20.0f / 255.0f, 212.0f / 255.0f, 1.0f);

	/* Initialize grid */
	grid = std::make_unique<Grid>(windowOptions.dim, gridOptions.gridSize, gridOptions.gridColor);

	/* Add all cameras */
	this->addCamera<Camera>(
		glm::vec3(0.0f, 1.0f, 3.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		Constants::YAW,
		Constants::PITCH
		);

	// Load model
	// std::string path = "resources/models/crisis.assimp";
	// this->addElement<Model>(Model(path));

	/* Add all mesh elements */
	this->addElement<Cube>(
		std::make_shared<Material>(
			MaterialType::EMERALD,
			construct_inplace_vec_by_move(
				std::make_unique<Texture>("resources/textures/wooden_box.png"),
				std::make_unique<Texture>("resources/textures/wooden_box_specular.png")
			)
			)
		);

	/* Add lights after mesh elements for consistency */
	this->addLighting<OmniDirectionLight>(
		glm::vec3(0.8f, 1.4f, 2.0f),	// Origin
		glm::vec3(1.0f, 1.0f, 1.0f),	// Light Color
		glm::vec3(0.2f),				// Ambient Factor
		glm::vec3(0.5f),				// Diffuse Factor
		glm::vec3(1.0f)					// Specular Factor
		);
};

Void::Void(WindowOptions windowOptions, WorldOptions worldOptions, GridOptions gridOptions) :
	World(windowOptions, worldOptions, gridOptions)
{ };

int Void::load() {
	// Setup grid buffers
	grid->setupBuffers();

	// Setup all element buffers
	for (auto const& element : elements) {
		element->setupBuffers();
	}

	// Setup all light source buffers
	for (auto const& light : lightSources) {
		light->setupBuffers();
	}

	return 0;
}

int Void::onTick() {
	// Paint background color
	glClearColor(
		worldOptions.backgroundColor[0],
		worldOptions.backgroundColor[1],
		worldOptions.backgroundColor[2],
		worldOptions.backgroundColor[3]
	);

	// Clearing color and depth buffer each cycle
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw grid
	if (grid->show) {
		grid->draw(activeCamera, windowOptions.dim);
	}

	// Draw all elements
	for (auto const& element : elements) {
		for (auto const& light : lightSources) {
			// Sending lighting parameters to mesh shader
			// TODO: Add lightSources shared pointers to mesh directly during setup and call applyEffect during their draw call.
			light->applyEffect(element->getShader());
		}

		DrawOptions drawOptions = DrawOptions();
		drawOptions.showWireframe = showWireframe;
		element->draw(activeCamera, windowOptions.dim, drawOptions);
	}

	// Draw all light sources
	for (auto const& light : lightSources) {
		light->draw(activeCamera, windowOptions.dim);
	}

	return 0;
}

int Void::cleanup() {
	// Clear grid buffers
	grid->deleteBuffers();

	// Clear all element buffers
	for (auto const& element : elements) {
		element->deleteBuffers();
	}

	// Clear all light source buffers
	for (auto const& light : lightSources) {
		light->deleteBuffers();
	}

	return 0;
}
