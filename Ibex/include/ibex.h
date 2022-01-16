#pragma once

#ifndef IBEX_H
#define IBEX_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <world/world.h>

namespace Ibex {
	class Engine {
		GLFWwindow* window;

	protected:
		template <typename WT>
		int loadWorld(WT* world) {
			activeWorld = world;
			return 0;
		}
	public:
		bool dumped;
		World* activeWorld;

		template <typename WT>
		Engine& withWorld(WT* world) {
			this->activeWorld = world;
			return *this;
		}

		Engine();

		int init();
		int tick();
		int dump();
	};
}

#endif
