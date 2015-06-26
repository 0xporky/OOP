
#include "stdafx.h"
#include "Mage.h"

Mage::Mage(const char* unit_name) : Unit(15, 8, 30, unit_name), curse_chance(30), curse_dmg(50) {
	this->set_name_prefix("Mage");
}

const bool Mage::attack(Unit* u) {
	bool is_curse_attack = this->gr.get_chance(this->curse_chance);
	if (is_curse_attack) {
		int op_dmg_power  = u->get_damage_power();
		double curse_percent = this->gr.get_rand_number(0, 51) / 100.0;

		int damage = (int)(op_dmg_power * curse_percent);
		if (damage == 0) damage = 1;
		u->curse_unit(damage);

		char* tmp = " make cast. ";
		int buff_len = strlen(tmp) + strlen(this->get_unit_name()) + 1;
		char *buff = new char[buff_len];

		sprintf_s(buff, buff_len, "%s%s", this->get_unit_name(), tmp);
		this->set_message(buff);
		delete[] buff;
		return false; // при отруєнні суперник лишається живим
	}
	return Unit::attack(u);
}