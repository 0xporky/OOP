// XStringMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XString.h"

#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	XString s1("test"), s2("test2"), s3, s4, s5;
	XString ss1("Microsoft"), ss2("Windows"), ss4;
	XString aa1("Microsoft"), aa2("Windows");
	XString bb1("Microsoft"), bb2("Windows");

	cout << "Testig get_str(): \t"<< s1.get_str() << endl;

	s3 = s1 + s2;
	cout << "Testing s3 = s1 + s2: \t" << s3.get_str() << endl;

	s3 += " Andrew Komar";
	cout << "s2 + Andrew Komar: \t" << s3.get_str() << endl;

	s4 = "Superman " + s1 ;
	cout << "Superman + s1: \t\t" << s4.get_str() << endl;

	ss4 = ss1 * ss2;
	cout << "* \t\t\t" << ss4.get_str() << endl;

	aa1 *= aa2;
	cout << "*= \t\t\t" << aa1.get_str() << endl;

	ss4 = ss1 / ss2;
	cout << "/ \t\t\t" << ss4.get_str() << endl;

	bb1 /= bb2;
	cout << "/= \t\t\t" << bb1.get_str() << endl;

	s1[3] = 'x';
	cout << s1.get_str() << endl;

	s5 = s2(2, 2);
	cout << s5.get_str() << endl;

	if (s5 < s4) cout << "s5 < s4" << endl;
	else cout << "s5 >= s4" << endl;

	if (s5 < "test") cout << "s5 < test" << endl;
	else cout << "s5 >= test" << endl;

	if ("test" < s5) cout << "test < s5" << endl;
	else cout << "test >= s5" << endl;
	
	return 0;
}

