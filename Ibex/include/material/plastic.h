#pragma once

#ifndef PLASTIC_H
#define PLASTIC_H

#include "material.h"

class Plastic : public Material {
public:
	Plastic();
	Plastic(glm::vec3, glm::vec3, glm::vec3, float);
};

#endif
