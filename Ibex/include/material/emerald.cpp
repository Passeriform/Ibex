#include "emerald.h"
#include "material_registry.h"

Emerald::Emerald() : Material(MATERIAL_REGISTRY[MaterialType::EMERALD]) { }

Emerald::Emerald(std::vector<Texture*> textures) : Material(textures) { }

Emerald::Emerald(MaterialLightMap materialLightMap) : Material(materialLightMap) { }

Emerald::Emerald(MaterialLightMap materialLightMap, std::vector<Texture*> textures) : Material(materialLightMap, textures) { }
