#include "plastic.h"

Plastic::Plastic() : Material(
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.55f, 0.55f, 0.55f),
	glm::vec3(0.70f, 0.70f, 0.70f),
	51.2
) { }

Plastic::Plastic(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shine) : Material(ambient, diffuse, specular, shine) { }
