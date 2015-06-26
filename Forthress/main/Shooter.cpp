
#include "stdafx.h"
#include "Shooter.h"

Shooter::Shooter(const char *am_name, const int am_number) : am_number(am_number) {
	this->set_amunition_name(am_name);
}

Shooter::~Shooter() {
	delete[] this->am_name;
}

void Shooter::shoot() {
	if (this->am_number > 0) {
		cout << "Shoot with 1 " << this->am_name << endl;
		this->am_number--;
	}
	else {
		cout << "Not enough amunition to shoot." << endl;
	}
}

void Shooter::set_amunition(const char *am_name, const int am_number) {
	delete[] this->am_name;
	this->set_amunition_name(am_name);
	this->am_number = am_number;
	cout << "Change amunition to " << this->am_number << " " << this->am_name << endl;
}

void Shooter::set_amunition_name(const char *am_name) {
	int am_name_len = strlen(am_name) + 1;
	this->am_name = new char[am_name_len];
	strcpy_s(this->am_name, am_name_len, am_name);
}