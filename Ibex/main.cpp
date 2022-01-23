#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <ibex.h>
#include <world/void.h>
#include <model/model.h>

int main() {
	Ibex::Engine core = Ibex::Engine()
		.withWorld<Void>(std::unique_ptr<Void>(new Void()));

	core.init();

	do {
		core.tick();
	} while (!core.dumped);

	core.dump();
	return 0;
}
