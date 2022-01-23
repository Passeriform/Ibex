#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture {
	unsigned int id;

	// TODO: Use operator= overloads werever possible.

public:
	std::string type;
	std::string path;

	Texture();
	Texture(const Texture&) = default;
	Texture(Texture&&) = default;
	Texture(unsigned int, std::string, std::string);
	Texture(std::string);

	int load(unsigned int);
};

#endif
