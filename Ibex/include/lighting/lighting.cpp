#include "lighting.h"

Lighting::Lighting() {
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

Lighting::Lighting(LightSource light) : Lighting() {
	lightSource = light;
}

Lighting::Lighting(glm::vec3 origin, glm::vec3 color) : Lighting() {
	lightSource.origin = origin;
	lightSource.color = color;
}

Lighting::Lighting(glm::vec3 origin, glm::vec3 color, glm::vec3 ambientFactor, glm::vec3 diffuseFactor, glm::vec3 specularFactor) : Lighting() {
	lightSource.origin = origin;
	lightSource.color = color;
	lightSource.ambientFactor = ambientFactor;
	lightSource.diffuseFactor = diffuseFactor;
	lightSource.specularFactor = specularFactor;
}

int Lighting::setupShaders() {
	return 0;
}

int Lighting::draw(Camera* camera, std::pair<double, double>) {
	return 0;
}

int Lighting::deleteShadersAndBuffers() {
	return 0;
}

glm::vec3 Lighting::getPosition() {
	return lightSource.origin;
}

glm::vec3 Lighting::getColor() {
	return lightSource.color;
}

// TODO: Abstract under better options
glm::vec3 Lighting::getAmbientColor() {
	return getDiffuseColor() * lightSource.ambientFactor;
}

glm::vec3 Lighting::getDiffuseColor() {
	return lightSource.color * lightSource.diffuseFactor;
}

glm::vec3 Lighting::getSpecularColor() {
	return lightSource.specularFactor;
}
