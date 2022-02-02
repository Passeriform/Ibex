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
	Texture(unsigned int, std::string, std::string);
	Texture(std::string);

	int load(unsigned int);
};

#endif
