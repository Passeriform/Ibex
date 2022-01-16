#pragma once

#ifndef EMERALD_H
#define EMERALD_H

#include "material.h"

class Emerald : public Material {
public:
	Emerald();
	Emerald(std::vector<Texture*>);
	Emerald(MaterialLightMap);
	Emerald(MaterialLightMap, std::vector<Texture*>);
};

#endif
