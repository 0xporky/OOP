
#pragma once

#include <cstdlib>
#include <ctime>

class GameRandomizer {
public:
	GameRandomizer();

	const bool get_chance(int chance) const;
	const int get_rand_number(int start, int end) const;
};