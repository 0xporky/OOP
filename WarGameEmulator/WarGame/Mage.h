
#pragma once

#include "Unit.h"

class Mage : public Unit {
public:
	Mage(const char* unit_name);

	const virtual bool attack(Unit* u);

private:
	int curse_chance; // шанс удару магією
	int curse_dmg;    // на скільки процентів може зменшити атаку суперника
	GameRandomizer gr;
};