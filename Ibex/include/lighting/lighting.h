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

// TODO: Make Lighting a wrapper around generic Mesh, declare local Mesh variable handling render of light-emanating source.
// Call the mesh's render functions from within lighting.

class Lighting {
protected:
	unsigned int VAO, VBO, EBO;

	LightSource lightSource;
	std::unique_ptr<Shader> lightingShader;

public:
	Lighting();
	Lighting(LightSource);
	Lighting(glm::vec3);
	Lighting(glm::vec3, glm::vec3, glm::vec3, glm::vec3);

	virtual int applyEffect(Shader&);
	virtual int setupBuffers();
	virtual int draw(std::shared_ptr<Camera>, std::pair<float, float>);
	virtual int deleteBuffers();
};

#endif
