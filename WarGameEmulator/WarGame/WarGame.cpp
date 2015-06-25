// WarGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Army.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void represent_armies(Army &army1, Army &army2, const int unit_num);
void print_line();
void print_data_line(const char *n1, const char *n2);
void print_data_line(const UnitParams &n1, const UnitParams &n2);
void swap_army(Army *&army1, Army *&army2);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(unsigned(time(0)));

	const int unit_num = 3;
	GameRandomizer gr;
	Army Orcs(unit_num, "Orcs"), Humans(unit_num, "Humans");
	Army* attacker = nullptr, * defender = nullptr, *buff = nullptr;

	cout << "Armies created.\n\n";
	represent_armies(Orcs, Humans, unit_num);

	int rnd = gr.get_rand_number(0, 101);
	if (rnd <= 50) {
		attacker = &Orcs;
		defender = &Humans;
	}
	else {
		attacker = &Humans;
		defender = &Orcs;
	}

	cout << "Battle begins.\n\n";
	cin.get();

	system("cls");
	
	bool result = false;
	while (result == false) {
		cout << attacker->get_name() << " attacks!" << endl;
		result = attacker->attack(defender);
		cout << attacker->say() << endl;
		cout << defender->say() << endl;
		if (result) {
			cout << attacker->get_name() << " wins!" << endl;
		}
		represent_armies(Orcs, Humans, unit_num);
		swap_army(attacker, defender);
		cin.get();
		system("cls");
	}

	return 0;
}

void swap_army(Army *&army1, Army *&army2) {
	Army *tmp = army1;
	army1 = army2;
	army2 = tmp;
}

void represent_armies(Army &army1, Army &army2, const int unit_num) {

	print_line();
	print_data_line("ORKS", "HUMANS");
	print_line();

	for (int i = 0; i < unit_num; i++) {
		UnitParams up1 = army1.get_unit_params_by_id(i);
		UnitParams up2 = army2.get_unit_params_by_id(i);
		print_data_line(up1, up2);
		print_line();
	}
}

void print_line() {

	cout << "+";
	cout.fill('-');
	cout.width(1);
	cout << "-";

	cout << "+";
	cout.fill('-');
	cout.width(25);
	cout << "-";

	cout << "+";
	cout.fill('-');
	cout.width(3);
	cout << "-";

	cout << "+";
	cout.fill('-');
	cout.width(3);
	cout << "-";

	cout << "+";
	cout.fill('-');
	cout.width(3);
	cout << "-";

	cout << "+";

	cout << "    ";

	cout << "+";
	cout.fill('-');
	cout.width(1);
	cout << "-";

	cout << "+";
	cout.fill('-');
	cout.width(25);
	cout << "-";

	cout << "+";
	cout.fill('-');
	cout.width(3);
	cout << "-";

	cout << "+";
	cout.fill('-');
	cout.width(3);
	cout << "-";

	cout << "+";
	cout.fill('-');
	cout.width(3);
	cout << "-";

	cout << "+";

	cout << endl;
}

void print_data_line(const char *n1, const char *n2) {

	cout << "|";
	cout.fill(' ');
	cout.width(1);
	cout << " ";

	cout << "|";
	cout.fill(' ');
	cout.width(25);
	cout << n1;

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << "hp";

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << "dmg";

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << "dod";

	cout << "|";

	cout << " vs ";

	cout << "|";
	cout.fill(' ');
	cout.width(1);
	cout << " ";

	cout << "|";
	cout.fill(' ');
	cout.width(25);
	cout << n2;

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << "hp";

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << "dmg";

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << "dod";

	cout << "|";

	cout << endl;
}

void print_data_line(const UnitParams &n1, const UnitParams &n2) {
	cout << "|";
	cout.fill(' ');
	cout.width(1);
	cout << (n1.is_alive ? " " : "x");

	cout << "|";
	cout.fill(' ');
	cout.width(25);
	cout << n1.name;

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << n1.hp;

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << n1.dmg;

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << n1.dodge;

	cout << "|";

	cout << "    ";

	cout << "|";
	cout.fill(' ');
	cout.width(1);
	cout << (n2.is_alive ? " " : "x");;

	cout << "|";
	cout.fill(' ');
	cout.width(25);
	cout << n2.name;

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << n2.hp;

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << n2.dmg;

	cout << "|";
	cout.fill(' ');
	cout.width(3);
	cout << n2.dodge;

	cout << "|";

	cout << endl;
}