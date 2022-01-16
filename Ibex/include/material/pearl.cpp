#include "pearl.h"
#include "material_registry.h"

Pearl::Pearl() : Material(MATERIAL_REGISTRY[MaterialType::PEARL]) { }

Pearl::Pearl(std::vector<Texture*> textures) : Material(textures) { }

Pearl::Pearl(MaterialLightMap materialLightMap) : Material(materialLightMap) { }

Pearl::Pearl(MaterialLightMap materialLightMap, std::vector<Texture*> textures) : Material(materialLightMap, textures) { }
