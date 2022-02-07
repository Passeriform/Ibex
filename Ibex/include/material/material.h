#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H

#include <vector>
#include <memory>
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
	std::vector<std::unique_ptr<Texture>> textures;

public:
	MaterialLightMap materialLightMap;

	Material();

	Material(const Material&);
	Material& operator=(const Material&);

	Material(MaterialLightMap);
	Material(MaterialType);
	Material(MaterialType, std::vector<std::unique_ptr<Texture>>);
	Material(MaterialLightMap, std::vector<std::unique_ptr<Texture>>);

	bool isTextured();
	int setupBuffers();
};

#endif
