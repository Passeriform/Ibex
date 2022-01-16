#include <glm/glm.hpp>

#include "material.h"

Material::Material() :
	materialLightMap(
		{
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			40.0f
		}
	)
{ }

Material::Material(std::vector<Texture*> textures) : Material() {
	this->textures = textures;
}

Material::Material(MaterialLightMap materialLightMap) : Material() {
	this->materialLightMap = materialLightMap;
}

Material::Material(MaterialType materialType) : Material(MATERIAL_REGISTRY[materialType]) { }

Material::Material(MaterialLightMap materialLightMap, std::vector<Texture*> textures) : Material(materialLightMap) {
	this->textures = textures;
}

Material::Material(MaterialType materialType, std::vector<Texture*> textures) : Material(MATERIAL_REGISTRY[materialType], textures) { }

bool Material::isTextured() {
	return textures.size();
}

int Material::setupBuffers() {
	unsigned int textureIndex = 0;
	for (auto texture : textures) {
		texture->load(textureIndex);
		++textureIndex;
	}

	return 0;
}