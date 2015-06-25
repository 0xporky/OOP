
#include "stdafx.h"
#include "GameRandomizer.h"

GameRandomizer::GameRandomizer() {
}

const bool GameRandomizer::get_chance(int chance) const {
	if (chance > 99) {
		return true;
	}
	else if (chance < 1) {
		return false;
	}
	int rnd = this->get_rand_number(0, 101);
	if (rnd > chance) {
		return false;
	}
	return true;
}

const int GameRandomizer::get_rand_number(int start, int end) const {
	return start + rand() % end;
}