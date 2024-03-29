#pragma once

#ifndef IBEX_H
#define IBEX_H

#include <memory>
#include <world/world.h>
#include <utility/utility.h>

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

	using EngineDeleter = std::function<void(Engine*)>;
	extern EngineDeleter defaultEngineDeleter;
	extern EngineDeleter emptyEngineDeleter;
}

#endif
