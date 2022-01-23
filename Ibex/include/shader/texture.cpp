#include <iostream>
#include <boost/filesystem.hpp>
#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION 
#include <stb_image/stb_image.h>

#include "texture.h"

Texture::Texture() : Texture("resources/textures/default_texture_map.jpg") { }

Texture::Texture(unsigned int id, std::string type, std::string path) :
	id(id),
	type(type),
	path(path)
{ }

Texture::Texture(std::string imagePath) :
	id(-1),
	path(imagePath)
{ }

int Texture::load(unsigned int textureOffset) {
	glActiveTexture(GL_TEXTURE0 + textureOffset);
	glGenTextures(1, &this->id);
	glBindTexture(GL_TEXTURE_2D, this->id);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);

	// load and generate the texture
	int width, height, nrChannels;
	stbi_uc* data = stbi_load(
		boost::filesystem::absolute(
			boost::filesystem::path(this->path.c_str())
		).string().c_str(),
		&width,
		&height,
		&nrChannels,
		0
	);

	if (data) {
		GLenum format = GL_RGB;
		switch (nrChannels) {
		case 1: format = GL_RED; break;
		case 3: format = GL_RGB; break;
		case 4: format = GL_RGBA; break;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);


		stbi_image_free(data);

		return 0;
	}
	else {
		std::cout << "Texture failed to load at path: " << this->path << std::endl;
		stbi_image_free(data);

		return -1;
	}
}
