#include<utility>

#include <ibex.h>
#include <world/void.h>

#include <iostream>

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void error_callback(int error, const char* description);
//void mouse_callback(GLFWwindow* window, int button, int action, int mods);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);

int main()
{
	const int gridSize = 32;
	const std::pair<unsigned int, unsigned int> scrDim = std::make_pair(32 * gridSize, 32 * gridSize);

	Ibex::Engine core = Ibex::Engine()
		.withGridSize(gridSize)
		.withScrDim(scrDim)
		.withWorld<Void>(Void());

	core.init();

	do {
		core.tick();
	} while (!core.dumped);
	
	core.dump();
	return 0;
}