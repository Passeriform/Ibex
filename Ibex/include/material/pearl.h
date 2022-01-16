#pragma once

#ifndef PEARL_H
#define PEARL_H

#include "material.h"

class Pearl : public Material {
public:
	Pearl();
	Pearl(std::vector<Texture*>);
	Pearl(MaterialLightMap);
	Pearl(MaterialLightMap, std::vector<Texture*>);
};

#endif
