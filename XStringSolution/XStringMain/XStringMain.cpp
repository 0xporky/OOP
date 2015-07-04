// XStringMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XString.h"
#include "Var.h"

#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char str[200];
	bool loop = true;
	int index = 0;

	cout << "Enter the line: ";
	cin.getline(str, sizeof(str));

	XString my_str(str);

	while (loop) {
		cout << "Enter the number of character (-1 to exit): ";
		cin >> index;
		char ch = 0;

		if (index == -1) {
			loop = false;
			continue;
		}

		try {
			ch = my_str[index];
		}
		catch (const std::range_error &e) {
			cout << "Range error: " << e.what() << endl;
			continue;
		}
		catch (...) {
			cout << "Unknown error.\n";
			continue;
		}

		cout << "Char is: " << ch << endl;
	}

	cout << "\n\n\n\n";

	Var a = 123.456;
	a[0] = '0';
	cout << a << endl; // 120.456
	a[-1] = '8';
	cout << a << endl; // 120.486
	a += 7;
	cout << a << endl;  // 127.486

	try {
		a[20] = '5';
	} 
	catch (const std::range_error &e) {
		cout << "Range error: " << e.what() << endl;
	}
	catch (...) {
		cout << "Unknown error.\n";
	}
	
	return 0;
}

