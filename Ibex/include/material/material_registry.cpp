#include "material_registry.h"

std::unordered_map<MaterialType, MaterialLightMap> MATERIAL_REGISTRY = {
	{
		MaterialType::EMERALD, {
			glm::vec3(0.0215f, 0.1745f, 0.0215f),
			glm::vec3(0.07568f, 0.61424f, 0.07568f),
			glm::vec3(0.633f, 0.727811f, 0.633f),
			76.8f,
		}
	},
	{
		MaterialType::GOLD, {
			glm::vec3(0.24725f, 0.1995f, 0.0745f),
			glm::vec3(0.75164f, 0.60648f, 0.22648f),
			glm::vec3(0.628281f, 0.555802f, 0.366065f),
			51.2f,
		}
	},
	{
		MaterialType::PEARL, {
			glm::vec3(0.25f, 0.20725f, 0.20725f),
			glm::vec3(1.0f, 0.829f, 0.829f),
			glm::vec3(0.296648f, 0.296648f, 0.296648f),
			11.264f,
		}
	},
	{
		MaterialType::PLASTIC, {
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.55f, 0.55f, 0.55f),
			glm::vec3(0.70f, 0.70f, 0.70f),
			51.2,
		}
	}
};
