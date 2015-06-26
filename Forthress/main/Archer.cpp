
#include "stdafx.h"
#include "Archer.h"

Archer::Archer(const char *am_name, const int am_number) : Shooter(am_name, am_number)
{}

void Archer::shoot() {
	cout << "Archer is shooting." << endl;
	Shooter::shoot();
}