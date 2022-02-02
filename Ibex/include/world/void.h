#pragma once

#ifndef VOID_H
#define VOID_H

#include "world.h"

class Void : public World {
public:
	Void();
	Void(WindowOptions, WorldOptions, GridOptions);
	int load() override;
	int onTick() override;
	int cleanup() override;
};

#endif
