
#pragma once

#include "Shooter.h"

class Catapult : public Shooter {
public:
	Catapult(const char *am_name, const int am_number);

	virtual void shoot();
};