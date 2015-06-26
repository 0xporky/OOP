// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Fortress.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Fortress ar(4, 2);
	ar.shoot();
	cin.get();
	ar.shoot();
	cin.get();
	ar.shoot();
	cin.get();
	ar.shoot();
	cin.get();

	return 0;
}

