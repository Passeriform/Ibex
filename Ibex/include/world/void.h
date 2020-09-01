#pragma once

#ifndef VOID_H
#define VOID_H

#include "world.h"

class Void : public World {
public:
	Void();
	Void(WorldConfig, CameraConfig, ShaderConfig, WindowConfig);
	int load();
	int onTick();
	int cleanup();
};

#endif
