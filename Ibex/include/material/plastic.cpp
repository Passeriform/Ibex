#include "plastic.h"
#include "material_registry.h"

Plastic::Plastic() : Material(MATERIAL_REGISTRY[MaterialType::PLASTIC]) { }

Plastic::Plastic(std::vector<Texture*> textures) : Material(textures) { }

Plastic::Plastic(MaterialLightMap materialLightMap) : Material(materialLightMap) { }

Plastic::Plastic(MaterialLightMap materialLightMap, std::vector<Texture*> textures) : Material(materialLightMap, textures) { }