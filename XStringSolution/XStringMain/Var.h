
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>

enum VarStatus {intvar=1, doublevar, strvar};

class Var {
public:
	Var();
	Var(int var);
	Var(double var);
	Var(std::string var);

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

	Var &operator [] (const int idx);
	Var &operator = (const char &right);

	const bool operator > (const Var &right);
	const bool operator < (const Var &right);

	const bool operator >= (const Var &right);
	const bool operator <= (const Var &right);

	const bool operator != (const Var &right);
	const bool operator == (const Var &right);

	friend std::ostream& operator << (std::ostream& op, const Var &right);
	friend std::istream& operator >> (std::istream& ip, Var &right);

	const int toint() const;
	const double todouble() const;
	const std::string toxstring() const;

private:

	const void cpy_obj(const Var &obj);
	const bool check_range(const int idx) const;

	int ivar;
	double dvar;
	std::string strvar;
	
	int index;

	VarStatus status;

};