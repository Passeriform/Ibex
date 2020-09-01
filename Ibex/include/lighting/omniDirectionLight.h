#pragma once

#ifndef OMNI_DIRECTION_LIGHT
#define OMNI_DIRECTION_LIGHT

#include "lighting.h"

class OmniDirectionLight : public Lighting {
public:
	OmniDirectionLight();
	OmniDirectionLight(LightSource);
	OmniDirectionLight(glm::vec3, glm::vec3);
	int setupShaders();
	int draw(Camera*, std::pair<double, double>);
};

#endif
