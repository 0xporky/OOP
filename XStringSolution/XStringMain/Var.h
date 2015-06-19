
#pragma once

#include "XString.h"
#include <iostream>

enum VarStatus {intvar=1, doublevar, xstrvar};

class Var {
public:
	Var();
	Var(int var);
	Var(double var);
	Var(XString var);

	Var(Var &obj);

	Var& operator = (const Var &right);

	Var operator * (const Var &right);
	Var operator / (const Var &right);
	Var operator + (const Var &right);
	Var operator - (const Var &right);

	Var operator += (const Var &right);
	Var operator *= (const Var &right);
	Var operator /= (const Var &right);
	Var operator -= (const Var &right);

	const bool operator > (const Var &right);
	const bool operator < (const Var &right);

	const bool operator >= (const Var &right);
	const bool operator <= (const Var &right);

	const bool operator != (const Var &right);
	const bool operator == (const Var &right);

	friend std::ostream& operator << (std::ostream& op, const Var &right);
	std::istream& operator >> (std::istream& ip);

	const int toint() const;
	const double todouble() const;
	const XString toxstring() const;

private:

	const void cpy_obj(const Var &obj);

	int ivar;
	double dvar;
	XString xsvar;

	VarStatus status;

};