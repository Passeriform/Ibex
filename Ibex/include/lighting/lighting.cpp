#include "lighting.h"

Lighting::Lighting() {
	lightSource = LightSource{
		glm::vec3(0.0f, 0.0f, 0.0f),	// origin
		glm::vec3(1.0f, 1.0f, 1.0f),	// color
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

int Lighting::setupShaders() {
	return 0;
}

int Lighting::draw(Camera* camera, std::pair<double, double>) {
	return 0;
}

int Lighting::deleteShadersAndBuffers() {
	return 0;
}

glm::vec3 Lighting::getColor() {
	return lightSource.color;
}
