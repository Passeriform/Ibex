#pragma once

#ifndef OMNI_DIRECTION_LIGHT_H
#define OMNI_DIRECTION_LIGHT_H

#include "lighting.h"

class OmniDirectionLight : public Lighting {
public:
	OmniDirectionLight();
	OmniDirectionLight(LightSource);
	OmniDirectionLight(glm::vec3, glm::vec3);
	OmniDirectionLight(glm::vec3, glm::vec3, glm::vec3, glm::vec3, glm::vec3);
	int setupShaders();
	int draw(Camera*, std::pair<double, double>);
};

#endif
