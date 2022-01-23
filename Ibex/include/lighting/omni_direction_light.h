#pragma once

#ifndef OMNI_DIRECTION_LIGHT_H
#define OMNI_DIRECTION_LIGHT_H

#include "lighting.h"

struct OmniLightSource : public LightSource {
	glm::vec3 origin;

public:
	OmniLightSource();
	OmniLightSource(const OmniLightSource&) = default;
	OmniLightSource(glm::vec3, glm::vec3, glm::vec3, glm::vec3, glm::vec3);
};

class OmniDirectionLight : public Lighting {
	OmniLightSource lightSource;

public:
	OmniDirectionLight();
	OmniDirectionLight(OmniLightSource);
	OmniDirectionLight(glm::vec3, glm::vec3);
	OmniDirectionLight(glm::vec3, glm::vec3, glm::vec3, glm::vec3, glm::vec3);

	int applyEffect(Shader&);
	int setupShadersAndBuffers();
};

#endif
