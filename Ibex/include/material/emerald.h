#pragma once

#ifndef EMERALD_H
#define EMERALD_H

#include "material.h"

class Emerald : public Material {
public:
	Emerald();
	Emerald(glm::vec3, glm::vec3, glm::vec3, float);
};

#endif
