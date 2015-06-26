
#pragma once

#include "Shooter.h"

class Archer : public virtual Shooter {
public:
	Archer(const char *am_name, const int am_number);

	virtual void shoot();
};