#pragma once

#ifndef LIGHTING_H
#define LIGHTING_H

#include <glm/gtc/matrix_transform.hpp>

#include <shader/shader.h>
#include <camera/camera.h>

struct LightSource {
	glm::vec3 color;

	glm::vec3 ambientFactor;
	glm::vec3 diffuseFactor;
	glm::vec3 specularFactor;

	std::string vertexShaderPath, fragmentShaderPath;

public:
	LightSource();
	LightSource(const LightSource&) = default;
	LightSource(glm::vec3, glm::vec3, glm::vec3, glm::vec3);
};

class Lighting {
protected:
	unsigned int VAO, VBO;

	LightSource lightSource;
	std::unique_ptr<Shader> lightingShader;

public:
	Lighting();
	Lighting(LightSource);
	Lighting(glm::vec3);
	Lighting(glm::vec3, glm::vec3, glm::vec3, glm::vec3);

	virtual int applyEffect(Shader&);
	virtual int setupShadersAndBuffers();
	virtual int draw(std::shared_ptr<Camera>, std::pair<double, double>);
	virtual int deleteShadersAndBuffers();
};

#endif
