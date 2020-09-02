#include "gold.h"

Gold::Gold() : Material(
	glm::vec3(0.24725f, 0.1995f, 0.0745f),
	glm::vec3(0.75164f, 0.60648f, 0.22648f),
	glm::vec3(0.628281f, 0.555802f, 0.366065f),
	51.2f
) { }

Gold::Gold(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shine) : Material(ambient, diffuse, specular, shine) { }
