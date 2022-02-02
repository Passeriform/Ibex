#include "omni_direction_light.h"

OmniLightSource::OmniLightSource() : LightSource() {
	origin = glm::vec3(0.0f);
}

OmniLightSource::OmniLightSource(
	glm::vec3 origin,
	glm::vec3 color,
	glm::vec3 ambientFactor,
	glm::vec3 diffuseFactor,
	glm::vec3 specularFactor
) :
	LightSource(color, ambientFactor, diffuseFactor, specularFactor)
{
	this->origin = origin;
}

OmniDirectionLight::OmniDirectionLight() : Lighting() { }

OmniDirectionLight::OmniDirectionLight(OmniLightSource light) : OmniDirectionLight() {
	lightSource = light;
}

OmniDirectionLight::OmniDirectionLight(glm::vec3 origin, glm::vec3 color) : OmniDirectionLight() {
	lightSource.origin = origin;
	lightSource.color = color;
}

OmniDirectionLight::OmniDirectionLight(glm::vec3 origin, glm::vec3 color, glm::vec3 ambientFactor, glm::vec3 diffuseFactor, glm::vec3 specularFactor) : OmniDirectionLight() {
	lightSource = OmniLightSource(origin, color, ambientFactor, diffuseFactor, specularFactor);
}

int OmniDirectionLight::applyEffect(Shader& applicatorShader) {
	Lighting::applyEffect(applicatorShader);
	applicatorShader.setVec3("light.position", lightSource.origin);

	return 0;
}

int OmniDirectionLight::setupBuffers() {
	// Initialize lighting shader
	lightingShader = std::make_unique<Shader>(lightSource.vertexShaderPath, lightSource.fragmentShaderPath);

	// Separate VAO for each component initialized only once
	glGenVertexArrays(1, &VAO);

	// Bind the VAO
	glBindVertexArray(VAO);

	// Generate VBO for the component
	glGenBuffers(1, &VBO);

	// Bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(OmniLightSource), &lightSource, GL_STATIC_DRAW);

	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(OmniLightSource), reinterpret_cast<void*>(offsetof(OmniLightSource, origin)));
	glEnableVertexAttribArray(0);

	// Bind vertex position attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(OmniLightSource), reinterpret_cast<void*>(offsetof(OmniLightSource, color)));
	glEnableVertexAttribArray(1);

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}
