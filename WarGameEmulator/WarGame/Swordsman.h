
#include "Unit.h"

class Swordsman : public Unit {
public:
	Swordsman(const char* unit_name);
	
	const virtual bool attack(Unit* u);
};