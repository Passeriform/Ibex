#pragma once

#ifndef GOLD_H
#define GOLD_H

#include "material.h"

class Gold : public Material {
public:
	Gold();
	Gold(std::vector<Texture*>);
	Gold(MaterialLightMap);
	Gold(MaterialLightMap, std::vector<Texture*>);
};

#endif
