#pragma once

#ifndef MATERIAL_REGISTRY_H
#define MATERIAL_REGISTRY_H

#include <unordered_map>

#include "material.h"

enum MaterialType {
	EMERALD,
	GOLD,
	PEARL,
	PLASTIC,
};

extern std::unordered_map<unsigned int, MaterialLightMap> MATERIAL_REGISTRY;

#endif
