
#include "stdafx.h"
#include "ArcherTower.h"

ArcherTower::ArcherTower(const char *am_name, const int am_number) :
Archer(am_name, am_number), Ranger(am_name, am_number), Shooter(am_name, am_number)
{}

void ArcherTower::shoot() {
	Archer::shoot();
	Ranger::shoot();
}