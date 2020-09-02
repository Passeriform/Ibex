#pragma once

#ifndef PEARL_H
#define PEARL_H

#include "material.h"

class Pearl : public Material {
public:
	Pearl();
	Pearl(glm::vec3, glm::vec3, glm::vec3, float);
};

#endif
