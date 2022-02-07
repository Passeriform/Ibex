#include <ibex.h>
#include <world/void.h>

int main() {
	Ibex::Engine core = Ibex::Engine()
		.withWorld<Void>(std::make_unique<Void>());

	core.init();

	do {
		core.tick();
	} while (!core.dumped);

	core.dump();
	return 0;
}
