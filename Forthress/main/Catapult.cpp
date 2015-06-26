
#include "stdafx.h"
#include "Catapult.h"

Catapult::Catapult(const char *am_name, const int am_number) : Shooter(am_name, am_number)
{}

void Catapult::shoot() {
	cout << "Catapult is shooting." << endl;
	Shooter::shoot();
}