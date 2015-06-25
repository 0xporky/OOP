
#pragma once

#include "Unit.h"

class Archer : public Unit {
public:

	Archer(const char* unit_name);

	const virtual bool attack(Unit* u);

private:
	int crit_chance;
	GameRandomizer gr;
};