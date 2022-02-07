#include <algorithm>
#include <iterator>

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

Material::Material(const Material& material) : Material(material.materialLightMap) {
	textures.reserve(material.textures.size());
	std::transform(
		material.textures.begin(),
		material.textures.end(),
		std::back_inserter(textures),
		[](const std::unique_ptr<Texture>& uptr) {
			return std::unique_ptr<Texture>{ uptr ? new Texture{ *uptr } : nullptr };
		}
	);
}

Material& Material::operator=(const Material& material) {
	new (this) Material(material);
	return *this;
}


Material::Material(MaterialLightMap materialLightMap) : Material() {
	this->materialLightMap = materialLightMap;
}

Material::Material(MaterialType materialType) : Material(MATERIAL_REGISTRY[materialType]) { }

Material::Material(MaterialLightMap materialLightMap, std::vector<std::unique_ptr<Texture>> textures) : Material(materialLightMap) {
	this->textures = std::move(textures);
}

Material::Material(MaterialType materialType, std::vector<std::unique_ptr<Texture>> textures) : Material(MATERIAL_REGISTRY[materialType], std::move(textures)) { }

bool Material::isTextured() {
	return textures.size();
}

int Material::setupBuffers() {
	unsigned int textureIndex = 0;
	for (auto const& texture : textures) {
		texture->load(textureIndex);
		++textureIndex;
	}

	return 0;
}