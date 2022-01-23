#pragma once

#ifndef LIGHTING_H
#define LIGHTING_H

#include <glm/gtc/matrix_transform.hpp>

#include <shader/shader.h>
#include <camera/camera.h>

class Lighting {
public:
	unsigned int VAO, VBO;

	std::unique_ptr<Shader> lightingShader;

	Lighting();

	virtual glm::vec3 getPosition() = 0;
	virtual glm::vec3 getColor() = 0;
	virtual glm::vec3 getAmbientColor() = 0;
	virtual glm::vec3 getDiffuseColor() = 0;
	virtual glm::vec3 getSpecularColor() = 0;

	virtual int setupShadersAndBuffers() = 0;
	virtual int draw(std::shared_ptr<Camera>, std::pair<double, double>) = 0;
	virtual int deleteShadersAndBuffers() = 0;
};

#endif
