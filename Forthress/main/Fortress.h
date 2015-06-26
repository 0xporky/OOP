
#pragma once

#include "ArcherTower.h"
#include "Catapult.h"

class Fortress : public ArcherTower, public Catapult {
public:
	Fortress(const int arrows_number, const int stone_number);
	virtual void shoot();
};