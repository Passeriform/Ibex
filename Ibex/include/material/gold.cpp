#include "gold.h"
#include "material_registry.h"

Gold::Gold() : Material(MATERIAL_REGISTRY[MaterialType::GOLD]) { }

Gold::Gold(std::vector<Texture*> textures) : Material(textures) { }

Gold::Gold(MaterialLightMap materialLightMap) : Material(materialLightMap) { }

Gold::Gold(MaterialLightMap materialLightMap, std::vector<Texture*> textures) : Material(materialLightMap, textures) { }