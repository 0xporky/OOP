
#pragma once

#include "Swordsman.h"
#include "Archer.h"
#include "Mage.h"

#include <cctype>
#include <typeinfo>

enum UnitType { SwordsmanUnit = 1, ArcherUnit, MageUnit };

struct UnitParams {
	int hp;
	int dmg;
	int dodge;
	char name[80];
	bool is_alive;
};

class Army {
public:
	Army(int unit_num, const char* name);
	~Army();

	const bool attack(Army* army); // true ÿךשמ ןונולמדכט

	const char* say() const;
	const char* get_name() const;
	const void set_message(const char* message);

	const UnitParams get_unit_params_by_id(const int id) const;

	const void get_random_name(char* player_name) const;

private:
	Army(Army&);
	
	const bool is_defeated() const;
	Unit* get_rnd_unit() const;
	const bool get_same_unit(Unit* attacker, Unit* &defender) const;

	Unit** units;
	GameRandomizer gr;
	int unit_num;
	int alive_units;

	char* message;
	char* name;
};