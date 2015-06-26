
#include "stdafx.h"
#include "Fortress.h"

Fortress::Fortress(const int arrows_number, const int stone_number) :
ArcherTower("arrow", arrows_number),
Catapult("stone", stone_number),
ArcherTower::Shooter("arrow", arrows_number)
{
	
}

void Fortress::shoot() {
	ArcherTower::shoot();
	Catapult::shoot();
}