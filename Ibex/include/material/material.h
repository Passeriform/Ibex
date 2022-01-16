#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H

#include <vector>
#include <glm/glm.hpp>
#include <shader/texture.h>
#include <utility/utility.h>

#include "material_registry.h"

extern enum class MaterialType;

struct MaterialLightMap {
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
};

class Material {
	std::vector<Texture*> textures;

public:
	MaterialLightMap materialLightMap;

	Material();
	Material(std::vector<Texture*>);
	Material(MaterialLightMap);
	Material(MaterialType);
	Material(MaterialLightMap, std::vector<Texture*>);
	Material(MaterialType, std::vector<Texture*>);

	int setupBuffers();
};

#endif
