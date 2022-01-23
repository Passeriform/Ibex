#pragma once

#ifndef OMNI_DIRECTION_LIGHT_H
#define OMNI_DIRECTION_LIGHT_H

#include "lighting.h"

struct LightSource {
	glm::vec3 origin;
	glm::vec3 color;

	glm::vec3 ambientFactor;
	glm::vec3 diffuseFactor;
	glm::vec3 specularFactor;

	std::string vertexPath, fragmentPath;
};

class OmniDirectionLight : public Lighting {
	LightSource lightSource;

public:
	OmniDirectionLight();
	OmniDirectionLight(LightSource);
	OmniDirectionLight(glm::vec3, glm::vec3);
	OmniDirectionLight(glm::vec3, glm::vec3, glm::vec3, glm::vec3, glm::vec3);

	glm::vec3 getPosition();
	glm::vec3 getColor();
	glm::vec3 getAmbientColor();
	glm::vec3 getDiffuseColor();
	glm::vec3 getSpecularColor();

	int setupShadersAndBuffers();
	int draw(std::shared_ptr<Camera>, std::pair<double, double>);
	int deleteShadersAndBuffers();
};

#endif
