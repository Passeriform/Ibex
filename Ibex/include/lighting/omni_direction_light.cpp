#include "omni_direction_light.h"

OmniDirectionLight::OmniDirectionLight() : Lighting() {
	lightSource = LightSource{
			glm::vec3(0.0f),	// origin
			glm::vec3(1.0f),	// color
			glm::vec3(0.2),		// ambient
			glm::vec3(0.5),		// diffuse
			glm::vec3(1.0),		// specular
			"shaders/lightShader.vert",		// vertexShader
			"shaders/lightShader.frag",		// fragmentShader
	};
}

OmniDirectionLight::OmniDirectionLight(LightSource light) : OmniDirectionLight() {
	lightSource = light;
}

OmniDirectionLight::OmniDirectionLight(glm::vec3 origin, glm::vec3 color) : OmniDirectionLight() {
	lightSource.origin = origin;
	lightSource.color = color;
}

OmniDirectionLight::OmniDirectionLight(glm::vec3 origin, glm::vec3 color, glm::vec3 ambientFactor, glm::vec3 diffuseFactor, glm::vec3 specularFactor) : OmniDirectionLight() {
	lightSource.origin = origin;
	lightSource.color = color;
	lightSource.ambientFactor = ambientFactor;
	lightSource.diffuseFactor = diffuseFactor;
	lightSource.specularFactor = specularFactor;
}


glm::vec3 OmniDirectionLight::getPosition() {
	return lightSource.origin;
}

glm::vec3 OmniDirectionLight::getColor() {
	return lightSource.color;
}

// TODO: Abstract under better options
glm::vec3 OmniDirectionLight::getAmbientColor() {
	return getDiffuseColor() * lightSource.ambientFactor;
}

glm::vec3 OmniDirectionLight::getDiffuseColor() {
	return lightSource.color * lightSource.diffuseFactor;
}

glm::vec3 OmniDirectionLight::getSpecularColor() {
	return lightSource.specularFactor;
}

// TODO: Move relevant buffer binding to Lighting instead.
int OmniDirectionLight::setupShadersAndBuffers() {
	// Initialize lighting shader
	lightingShader = std::make_unique<Shader>(lightSource.vertexPath, lightSource.fragmentPath);

	// Separate VAO for each component initialized only once
	glGenVertexArrays(1, &VAO);

	// Bind the VAO
	glBindVertexArray(VAO);

	// Generate VBO for the component
	glGenBuffers(1, &VBO);

	// Bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(LightSource), &lightSource, GL_STATIC_DRAW);

	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(LightSource), (void*)0);
	glEnableVertexAttribArray(0);

	// Bind vertex position attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(LightSource), (void*)offsetof(LightSource, color));
	glEnableVertexAttribArray(1);

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}

int OmniDirectionLight::draw(std::shared_ptr<Camera> camera, std::pair<double, double> scrDim) {
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


int OmniDirectionLight::deleteShadersAndBuffers() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	return 0;
}
