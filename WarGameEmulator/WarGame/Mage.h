
#pragma once

#include "Unit.h"

class Mage : public Unit {
public:
	Mage(const char* unit_name);

	const virtual bool attack(Unit* u);

private:
	int curse_chance; // ���� ����� ��㳺�
	int curse_dmg;    // �� ������ �������� ���� �������� ����� ���������
	GameRandomizer gr;
};