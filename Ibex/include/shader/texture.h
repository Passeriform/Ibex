#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture {
	unsigned int id;

public:
	std::string type;
	std::string path;

	Texture();
	Texture(std::string imagePath);

	int load(unsigned int);
};

#endif
