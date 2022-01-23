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
	applicatorShader.setVec3("light.color", lightSource.color);
	applicatorShader.setVec3("light.ambient", lightSource.ambientFactor);
	applicatorShader.setVec3("light.diffuse", lightSource.diffuseFactor);
	applicatorShader.setVec3("light.specular", lightSource.specularFactor);

	return 0;
}

int Lighting::setupShadersAndBuffers() {
	// Initialize lighting shader
	lightingShader = std::make_unique<Shader>(lightSource.vertexShaderPath, lightSource.fragmentShaderPath);

	/*								Buffer Generation									*/
	/* -------------------------------------------------------------------------------- */

	// Generate VAO for the component
	glGenVertexArrays(1, &VAO);

	// Generate VBO for the component
	glGenBuffers(1, &VBO);

	// TODO: Check if EBO needs to be generated

	/*								Buffer Binding										*/
	/* -------------------------------------------------------------------------------- */

	// Bind the VAO
	glBindVertexArray(VAO);

	/*							Attribute Binding										*/
	/* -------------------------------------------------------------------------------- */

	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(LightSource), (void*)0);
	glEnableVertexAttribArray(0);

	// Bind vertex position attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(LightSource), (void*)offsetof(LightSource, color));
	glEnableVertexAttribArray(1);

	/*								Cleanup												*/
	/* -------------------------------------------------------------------------------- */

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}

int Lighting::draw(std::shared_ptr<Camera> camera, std::pair<double, double> scrDim) {
	// Use the dedicated lighting shader
	lightingShader->use();

	// Set projection, view and model matrices
	glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)scrDim.first / (float)scrDim.second, 0.1f, 100.0f);
	lightingShader->setMat4("projection", projection);

	glm::mat4 view = camera->GetViewMatrix();
	lightingShader->setMat4("view", view);

	glm::mat4 model = glm::mat4(1.0f);
	lightingShader->setMat4("model", model);

	// Set point styling uniforms
	glEnable(GL_PROGRAM_POINT_SIZE);
	lightingShader->setVec3("cameraeye", camera->Position);
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

int Lighting::deleteShadersAndBuffers() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	return 0;
}