#include <iostream>
#include<utility>

#include <ibex.h>
#include <world/void.h>

int main()
{
	Ibex::Engine core = Ibex::Engine()
		.withWorld<Void>(new Void());

	core.init();

	do {
		core.tick();
	} while (!core.dumped);

	core.dump();
	return 0;
}
