#pragma once

#ifndef IBEX_H
#define IBEX_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "world/world.h"

namespace Ibex {
	class Engine {
	public:
		long gridSize;
		unsigned int scrWidth;
		unsigned int scrHeight;
		bool dumped;

		GLFWwindow* window;
		World* activeWorld;

		Engine();

		Engine& withGridSize(long);
		Engine& withScrDim(std::pair<unsigned long, unsigned long>);
		Engine& withScrWidth(unsigned long);
		Engine& withScrHeight(unsigned long);
		template <typename WT>
		Engine& withWorld(WT world) {
			activeWorld = &world;

			activeWorld->setWindowDim(std::make_pair(scrWidth, scrHeight));

			return *this;
		}

		int init();
		int tick();
		int dump();
		template <typename WT>
		int loadWorld(WT world) {
			activeWorld = &world;

			activeWorld->setWindowDim(std::make_pair(scrWidth, scrHeight));

			return 0;
		}
	};
}

#endif