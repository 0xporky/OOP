
#pragma once

#include "GameRandomizer.h"
#include <cstring>

class Unit {
public:
	Unit(int hp, int dmg, int dodge, const char* unit_name);
	~Unit();

	const virtual bool attack(Unit* u) = 0; // true is kill opponent unit

	const int get_damage_power() const;
	const bool is_attack_avoided();
	const bool hit_unit(int damage);
	const void curse_unit(int damage);
	const bool is_unit_alive();

	const void set_message(char* message);
	const char* get_last_message() const;

	const char* get_unit_name() const;
	const void set_name_prefix(const char* prefix);

	const int get_unit_hp() const;
	const int get_unit_dmg() const;
	const int get_unit_dodge() const;

private:

	Unit(Unit&);

	int hp;
	int dmg;
	int dodge;

	char* last_message;
	int message_len;

	char* unit_name;
	int unit_name_len;

	GameRandomizer gr;
};