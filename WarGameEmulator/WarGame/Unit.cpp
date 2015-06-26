
#include "stdafx.h"
#include "Unit.h"

Unit::Unit(int hp, int dmg, int dodge, const char* unit_name) :hp(hp), dmg(dmg), dodge(dodge) {
	this->last_message = nullptr; 
	this->message_len = 0;

	this->unit_name_len = strlen(unit_name) + 1;
	this->unit_name = new char[unit_name_len];
	strcpy_s(this->unit_name, this->unit_name_len, unit_name);
}

Unit::~Unit() {
	delete[] this->last_message;
	this->last_message = nullptr;

	delete[] this->unit_name;
	this->unit_name = nullptr;

	this->message_len = 0;
	this->unit_name_len = 0;
}

const bool Unit::is_unit_alive() {
	bool is_alive = this->hp > 0 ? true : false;

	if (!is_alive) {
		char* tmp = " died.";
		int buff_len = this->message_len + this->unit_name_len + strlen(tmp) + 1;

		char* buff = new char[buff_len];

		sprintf_s(buff, buff_len, "%s%s%s", this->get_last_message(), this->get_unit_name(), tmp);
		this->set_message(buff);

		delete[] buff;
	}

	return is_alive;
}

const int Unit::get_damage_power() const {
	return this->dmg;
}

const bool Unit::is_attack_avoided() {
	bool result = this->gr.get_chance(this->dodge);
	char* tmp = " avoided.";
	int buff_len = this->unit_name_len + strlen(tmp) + 1;
	char* buff = new char[buff_len];

	sprintf_s(buff, buff_len, "%s%s", this->get_unit_name(), tmp);
	this->set_message(buff);

	delete[] buff;

	return result;
}

const bool Unit::hit_unit(int damage) {
	char *tmp = " got ", *tmp1 = " damage.";
	int buff_len = this->unit_name_len + strlen(tmp) + strlen(tmp1) + 5;
	char* buff = new char[buff_len];

	sprintf_s(buff, buff_len, "%s%s%d%s", this->get_unit_name(), tmp, damage, tmp1);
	this->set_message(buff);

	delete[] buff;

	this->hp -= damage;
	if (this->hp < 0) this->hp = 0;
	return this->is_unit_alive();
}

const void Unit::curse_unit(int damage) {

	char *tmp = " got ", *tmp1 = " curse.";
	int buff_len = this->unit_name_len + strlen(tmp) + strlen(tmp1) + 5;
	char* buff = new char[buff_len];

	sprintf_s(buff, buff_len, "%s%s%d%s", this->get_unit_name(), tmp, damage, tmp1);
	this->set_message(buff);

	delete[] buff;

	if (damage >= this->dmg) {
		this->dmg = 1;
		return;
	}
	this->dmg -= damage;
}

const bool Unit::attack(Unit *u) {
	int damage = 0;
	bool is_alive = true;
	char* tmp = " attacks ";
	int buff_len = this->unit_name_len + strlen(tmp) + u->unit_name_len + 2;
	char *buff = new char[buff_len];

	sprintf_s(buff, buff_len, "%s%s%s.", this->get_unit_name(), tmp, u->get_unit_name());
	this->set_message(buff);
	delete[] buff;

	if (u->is_attack_avoided()) {
		return false;
	}

	damage = this->get_damage_power();
	is_alive = u->hit_unit(damage);
	return !is_alive;
}

const void Unit::set_message(char* message) {
	this->message_len = strlen(message) + 1;
	delete[] this->last_message;

	this->last_message = new char[this->message_len];
	strcpy_s(this->last_message, this->message_len, message);
}

const char* Unit::get_last_message() const {
	return this->last_message;
}

const char* Unit::get_unit_name() const {
	return this->unit_name;
}

const void Unit::set_name_prefix(const char* prefix) {
	this->unit_name_len = this->unit_name_len + strlen(prefix) + 2;
	char* tmp = new char[this->unit_name_len];

	sprintf_s(tmp, this->unit_name_len, "%s %s", prefix, this->unit_name);
	delete[] this->unit_name;
	this->unit_name = tmp;
}

const int Unit::get_unit_hp() const {
	return this->hp;
}

const int Unit::get_unit_dmg() const {
	return this->dmg;
}

const int Unit::get_unit_dodge() const {
	return this->dodge;
}