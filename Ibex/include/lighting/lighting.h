#pragma once

#ifndef LIGHTING_H
#define LIGHTING_H

#include <glm/gtc/matrix_transform.hpp>

#include <shader/shader.h>
#include <camera/camera.h>

struct LightSource {
	glm::vec3 origin;
	glm::vec3 color;

	glm::vec3 ambientFactor;
	glm::vec3 diffuseFactor;
	glm::vec3 specularFactor;

	const char* vertexPath, * fragmentPath;
};

class Lighting {
public:
	unsigned int VAO, VBO;

	LightSource lightSource;

	Shader lightingShader;

	Lighting();
	Lighting(LightSource light);
	Lighting(glm::vec3, glm::vec3);
	Lighting(glm::vec3, glm::vec3, glm::vec3, glm::vec3, glm::vec3);
	virtual glm::vec3 getPosition();
	virtual glm::vec3 getColor();
	virtual glm::vec3 getAmbientColor();
	virtual glm::vec3 getDiffuseColor();
	virtual glm::vec3 getSpecularColor();
	virtual int setupShaders();
	virtual int draw(Camera*, std::pair<double, double>);
	virtual int deleteShadersAndBuffers();
};

#endif
