#include <world/world.h>

#include "lighting.h"

LightSource::LightSource() :
	color(glm::vec3(1.0f)),
	ambientFactor(glm::vec3(0.2)),
	diffuseFactor(glm::vec3(0.5)),
	specularFactor(glm::vec3(1.0)),
	vertexShaderPath("shaders/lightShader.vert"),
	fragmentShaderPath("shaders/lightShader.frag")
{ }

LightSource::LightSource(glm::vec3 color, glm::vec3 ambientFactor, glm::vec3 diffuseFactor, glm::vec3 specularFactor) : LightSource() {
	this->color = color;
	this->ambientFactor = ambientFactor;
	this->diffuseFactor = diffuseFactor;
	this->specularFactor = specularFactor;
}

Lighting::Lighting() :
	VAO(-1),
	VBO(-1),
	EBO(-1),
	lightingShader(nullptr)
{ }

Lighting::Lighting(LightSource light) : Lighting() {
	lightSource = light;
}

Lighting::Lighting(glm::vec3 color) : Lighting() {
	lightSource.color = color;
}

Lighting::Lighting(glm::vec3 color, glm::vec3 ambientFactor, glm::vec3 diffuseFactor, glm::vec3 specularFactor) : Lighting() {
	lightSource = LightSource(color, ambientFactor, diffuseFactor, specularFactor);
}

int Lighting::applyEffect(Shader& applicatorShader) {
	applicatorShader.use();
	applicatorShader.setVec3("light.color", lightSource.color);
	applicatorShader.setVec3("light.ambient", lightSource.ambientFactor);
	applicatorShader.setVec3("light.diffuse", lightSource.diffuseFactor);
	applicatorShader.setVec3("light.specular", lightSource.specularFactor);

	return 0;
}

int Lighting::setupBuffers() {
	// Initialize lighting shader
	lightingShader = std::make_unique<Shader>(lightSource.vertexShaderPath, lightSource.fragmentShaderPath);

	/*								Buffer Generation									*/
	/* -------------------------------------------------------------------------------- */

	// Generate VAO for the component
	glGenVertexArrays(1, &VAO);

	// Generate VBO for the component
	glGenBuffers(1, &VBO);

	// Generate EBO for the component
	// glGenBuffers(1, &EBO);

	/*								Buffer Binding										*/
	/* -------------------------------------------------------------------------------- */

	// Bind the VAO
	glBindVertexArray(VAO);

	// Bind the VBO
	// glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// glBufferData(GL_ARRAY_BUFFER, 1 * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	// Bind the EBO
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, locations.size() * sizeof(unsigned int), &locations[0], GL_STATIC_DRAW);

	/*							Attribute Binding										*/
	/* -------------------------------------------------------------------------------- */

	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(LightSource), reinterpret_cast<void*>(offsetof(LightSource, color)));
	glEnableVertexAttribArray(1);

	/*								Cleanup												*/
	/* -------------------------------------------------------------------------------- */

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}

int Lighting::draw(World* world) {
	// Use the dedicated lighting shader
	lightingShader->use();

	// Setting up model, view and projection matrices
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = world->getActiveCamera()->getViewMatrix();
	glm::mat4 projection = glm::perspective(
		glm::radians(world->getActiveCamera()->zoom),
		static_cast<float>(world->getWindowOptions().dim.first) / static_cast<float>(world->getWindowOptions().dim.second),
		0.1f,
		100.0f
	);

	// Setting model, view and projection matrices in the shader
	lightingShader->setMat4("model", model);
	lightingShader->setMat4("view", view);
	lightingShader->setMat4("projection", projection);

	// Set point styling uniforms
	glEnable(GL_PROGRAM_POINT_SIZE);
	lightingShader->setVec3("cameraeye", world->getActiveCamera()->position);
	lightingShader->setFloat("pointsize", 25.0f);
	lightingShader->setFloat("delta", 15.0f);

	// Bind the VAO before drawing lightSources
	glBindVertexArray(VAO);

	// Draw the lightSources (points)
	glDrawArrays(GL_POINTS, 0, 1);

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}

int Lighting::deleteBuffers() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	return 0;
}