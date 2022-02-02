#pragma once

#ifndef IBEX_H
#define IBEX_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <world/world.h>

namespace Ibex {
	class Engine {
		std::unique_ptr<GLFWwindow, GLFWwindowDeleter> window;
		std::unique_ptr<World> activeWorld;

		// Private non-writeable proxy
		bool isDumped;

		template <typename WT = World>
		int loadWorld(std::unique_ptr<WT> world) {
			activeWorld = std::move(world);
			return 0;
		}

	public:
		const bool& dumped = isDumped;

		template <typename WT = World>
		Engine& withWorld(std::unique_ptr<WT> world) {
			this->loadWorld(std::move(world));
			return *this;
		}

		Engine();
		Engine(Engine&);

		int init();
		int tick();
		int dump();

		std::unique_ptr<World>& getActiveWorld();
	};

	typedef void(*EngineDeleter)(Engine*);
	auto defaultEngineDeleter = [](Engine* core) { core->dump(); };
}

#endif
