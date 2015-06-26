
#pragma once

#include "Shooter.h"

class Ranger : public virtual Shooter {
public:
	Ranger(const char *am_name, const int am_number);

	virtual void shoot();
};