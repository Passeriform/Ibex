#include <iostream>
#include<utility>

#include <ibex.h>
#include <world/void.h>

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
