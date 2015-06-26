
#pragma once

#include "Archer.h"
#include "Ranger.h"

class ArcherTower : public Archer, public Ranger {
public:
	ArcherTower(const char *am_name, const int am_number);

	virtual void shoot();
};