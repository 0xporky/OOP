
#include "stdafx.h"
#include "Army.h"

Army::Army(int unit_num, const char* name) : unit_num(unit_num), alive_units(unit_num) {
	this->units = new Unit*[unit_num];
	int unit_type = 0, name_len = strlen(name) + 1;
	char player_name[21];

	for (int i = 0; i < unit_num; ++i) {
		unit_type = this->gr.get_rand_number(1, 3);
		memset(player_name, '\0', 21);
		this->get_random_name(player_name);
		switch (unit_type) {
		case UnitType::SwordsmanUnit:
			this->units[i] = new Swordsman(player_name);
			break;
		case UnitType::ArcherUnit:
			this->units[i] = new Archer(player_name);
			break;
		case UnitType::MageUnit:
			this->units[i] = new Mage(player_name);
			break;
		default:
			this->units[i] = new Swordsman(player_name);
			break;
		}
	}

	this->name = new char[name_len];
	strcpy_s(this->name, name_len, name);

	message = nullptr;
}

Army::~Army() {
	for (int i = 0; i < this->unit_num; i++) {
		delete this->units[i];
	}
	delete[]this->units;

	delete[] this->message;
	delete[] this->name;
}

Unit* Army::get_rnd_unit() const {
	int rnd_idx = this->gr.get_rand_number(0, this->unit_num);
	Unit* u = nullptr;
	do {
		u = this->units[rnd_idx];
		rnd_idx++;
		rnd_idx = rnd_idx >= this->unit_num ? 0 : rnd_idx;
	} while (!u->is_unit_alive());
	return u;
}

const bool Army::is_defeated() const {
	return this->alive_units <= 0 ? true : false;
}

const bool Army::attack(Army* army) {
	Unit* my_unit = this->get_rnd_unit();
	Unit* enemy_unit = nullptr;
	if (!army->get_same_unit(my_unit, enemy_unit)) {
		enemy_unit = army->get_rnd_unit();
	}
	
	bool result = my_unit->attack(enemy_unit);

	this->set_message(my_unit->get_last_message());
	army->set_message(enemy_unit->get_last_message());

	if (result) {
		army->alive_units--;
		return army->is_defeated();
	}

	return false;
}

const char* Army::say() const {
	return this->message;
}

const void Army::set_message(const char* message) {
	int message_len = strlen(message) + 1;

	delete[] this->message;

	this->message = new char[message_len];
	strcpy_s(this->message, message_len, message);
}

const void Army::get_random_name(char* player_name) const {

	char NamePrefix[][5] = {
		"",
		"bel", 
		"nar",
		"xan",
		"bell",
		"natr",
		"ev"
	};

	char NameSuffix[][5] = {
		"", "us", "ix", "ox", "ith",
		"ath", "um", "ator", "or", "axia",
		"imus", "ais", "itur", "orex", "o",
		"y"
	};

	const char NameStems[][10] = {
		"adur", "aes", "anim", "apoll", "imac",
		"educ", "equis", "extr", "guius", "hann",
		"equi", "amora", "hum", "iace", "ille",
		"inept", "iuv", "obe", "ocul", "orbis"
	};

	strcat_s(player_name, 21, NamePrefix[this->gr.get_rand_number(0, 7)]);
	strcat_s(player_name, 21, NameStems[this->gr.get_rand_number(0, 20)]);
	strcat_s(player_name, 21, NameSuffix[this->gr.get_rand_number(0, 16)]);
	player_name[0] = toupper(player_name[0]);

}

const UnitParams Army::get_unit_params_by_id(const int id) const {
	UnitParams up = {};
	if (id >= this->unit_num) {
		return up;
	}

	up.hp = this->units[id]->get_unit_hp();
	up.dmg = this->units[id]->get_unit_dmg();
	up.dodge = this->units[id]->get_unit_dodge();
	up.is_alive = this->units[id]->is_unit_alive();

	strcpy_s(up.name, sizeof(up.name), this->units[id]->get_unit_name());

	return up;
}

const char* Army::get_name() const {
	return this->name;
}

const bool Army::get_same_unit(Unit* attacker, Unit* &defender) const {
	Unit* tmp = nullptr;

	for (int i = 0; i < this->unit_num; i++) {
		if (this->units[i]->is_unit_alive() && typeid(*attacker) == typeid(*this->units[i])) {
			if (tmp == nullptr) {
				tmp = this->units[i];
			}
			else {
				if (tmp->get_unit_hp() < this->units[i]->get_unit_hp()) {
					tmp = this->units[i];
				}
			}
		}
	}

	if (tmp == nullptr) {
		return false;
	}

	defender = tmp;
	return true;
}