
#include "stdafx.h"
#include "Archer.h"

Archer::Archer(const char* unit_name) : Unit(10, 5, 40, unit_name), crit_chance(40) {
	this->set_name_prefix("Archer");
}

const bool Archer::attack(Unit* u) {
	int damage = 0;
	bool is_crit_attack = this->gr.get_chance(this->crit_chance);
	if (is_crit_attack) {
		damage = this->get_damage_power() * 2;
		bool is_alive = u->hit_unit(damage);

		char* tmp = " makes critical attack. ";
		int buff_len = strlen(tmp) + strlen(this->get_unit_name()) + 1;
		char *buff = new char[buff_len];

		sprintf_s(buff, buff_len, "%s%s", this->get_unit_name(), tmp);
		this->set_message(buff);
		delete[] buff;
		
		return !is_alive;
	}
	return Unit::attack(u);
}