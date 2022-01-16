#pragma once

#ifndef PLASTIC_H
#define PLASTIC_H

#include "material.h"

class Plastic : public Material {
public:
	Plastic();
	Plastic(std::vector<Texture*>);
	Plastic(MaterialLightMap);
	Plastic(MaterialLightMap, std::vector<Texture*>);
};

#endif
