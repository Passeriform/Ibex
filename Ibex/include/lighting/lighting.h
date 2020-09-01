#pragma once

#ifndef LIGHTING_H
#define LIGHTING_H

#include "shader.h"
#include "camera.h"

struct LightSource {
	glm::vec3 origin;
	glm::vec3 color;
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
	virtual glm::vec3 getColor();
	virtual int setupShaders();
	virtual int draw(Camera*, std::pair<double, double>);
	virtual int deleteShadersAndBuffers();
};

#endif
