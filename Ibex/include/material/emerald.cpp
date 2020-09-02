#include "emerald.h"

Emerald::Emerald() : Material(
	glm::vec3(0.0215f, 0.1745f, 0.0215f),
	glm::vec3(0.07568f, 0.61424f, 0.07568f),
	glm::vec3(0.633f, 0.727811f, 0.633f),
	76.8f
) { }

Emerald::Emerald(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shine) : Material(ambient, diffuse, specular, shine) { }
