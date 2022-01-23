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

/*
struct TextureList : std::vector<std::unique_ptr<Texture>> {
	using Base = std::vector<std::unique_ptr<Texture>>;
	using Base::Base;
	TextureList() = default;
	TextureList(TextureList&&) = default;
	TextureList& operator=(TextureList&&) = default;
};
*/

class Material {
	std::vector<std::unique_ptr<Texture>> textures;

public:
	MaterialLightMap materialLightMap;

	Material();

	Material(const Material&);
	Material& operator=(const Material&);

	/*
	Material(std::vector<Texture*>);
	Material(std::vector<std::unique_ptr<Texture>>);
	*/

	Material(MaterialLightMap);
	Material(MaterialType);
	Material(MaterialType, std::vector<std::unique_ptr<Texture>>);
	Material(MaterialLightMap, std::vector<std::unique_ptr<Texture>>);
	/*
	Material(MaterialType, std::vector<Texture*>);
	Material(MaterialLightMap, std::vector<Texture*>);
	*/

	bool isTextured();
	int setupBuffers();
};

#endif
