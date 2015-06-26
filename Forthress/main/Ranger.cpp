

#include "stdafx.h"
#include "Ranger.h"

Ranger::Ranger(const char *am_name, const int am_number) : Shooter(am_name, am_number)
{}

void Ranger::shoot() {
	cout << "Ranger is shooting." << endl;
	Shooter::shoot();
}