
#include "stdafx.h"
#include "Swordsman.h"

Swordsman::Swordsman(const char* unit_name) : Unit(20, 5, 60, unit_name) {
	this->set_name_prefix("Swordsman");
}

const bool Swordsman::attack(Unit* u) {
	return Unit::attack(u);
}