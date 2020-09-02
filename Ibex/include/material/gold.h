#pragma once

#ifndef GOLD_H
#define GOLD_H

#include "material.h"

class Gold : public Material {
public:
	Gold();
	Gold(glm::vec3, glm::vec3, glm::vec3, float);
};

#endif
