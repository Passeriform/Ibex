#pragma once

#ifndef IBEX_H
#define IBEX_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "world/world.h"

namespace Ibex {
	class Engine {
	public:
		bool dumped;

		GLFWwindow* window;
		World* activeWorld;

		Engine();

		template <typename WT>
		Engine& withWorld(WT* world) {
			this->activeWorld = world;
			return *this;
		}

		int init();
		int tick();
		int dump();
		template <typename WT>
		int loadWorld(WT world) {
			activeWorld = &world;
			return 0;
		}
	};
}

#endif
