#pragma once

#ifndef MATERIAL_REGISTRY_H
#define MATERIAL_REGISTRY_H

#include <unordered_map>

#include "material.h"

enum class MaterialType {
	EMERALD,
	GOLD,
	PEARL,
	PLASTIC,
};

extern struct MaterialLightMap;
extern std::unordered_map<MaterialType, MaterialLightMap> MATERIAL_REGISTRY;

#endif
