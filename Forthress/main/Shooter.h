
#pragma once

#include <iostream>

using namespace std;

class Shooter {
public:
	Shooter(const char *am_name, const int am_number);
	~Shooter();

	virtual void shoot();
	void set_amunition(const char *am_name, const int am_number);

private:

	void set_amunition_name(const char *am_name);

	char *am_name;
	int am_number;
};