
#include "stdafx.h"
#include "Var.h"

Var::Var() : ivar(0), status(VarStatus::intvar), index(0)
{}

Var::Var(int var) : ivar(var), status(VarStatus::intvar), index(0)
{}

Var::Var(double var) : dvar(var), status(VarStatus::doublevar), index(0)
{}

Var::Var(std::string var) : strvar(var), status(VarStatus::strvar), index(0)
{}


const void Var::cpy_obj(const Var &obj) {
	switch (obj.status)
	{
	case VarStatus::intvar:
		this->ivar = obj.ivar;
		this->status = obj.status;
		break;
	case VarStatus::doublevar:
		this->dvar = obj.dvar;
		this->status = obj.status;
		break;
	case VarStatus::strvar:
		this->strvar = obj.strvar;
		this->status = obj.status;
		break;
	default:
		this->ivar = 0;
		this->status = VarStatus::intvar;
		break;
	}
}


Var::Var(Var &obj) {
	this->cpy_obj(obj);
}


Var& Var::operator = (const Var &right) {
	if (this == &right) {
		return *this;
	}
	this->cpy_obj(right);
	return *this;
}

Var Var::operator * (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return Var(this->ivar * right.toint());
	}
	else if (this->status == VarStatus::doublevar) {
		return Var(this->dvar * right.todouble());
	}
	else if (this->status == VarStatus::strvar) {
		Var tmp(this->todouble() * right.todouble());
		return Var(tmp.toxstring());
	}

	return Var();
}

Var Var::operator / (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return Var(this->ivar / right.toint());
	}
	else if (this->status == VarStatus::doublevar) {
		return Var(this->dvar / right.todouble());
	}
	else if (this->status == VarStatus::strvar) {
		Var tmp(this->todouble() / right.todouble());
		return Var(tmp.toxstring());
	}

	return Var();
}

Var Var::operator + (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return Var(this->ivar + right.toint());
	}
	else if (this->status == VarStatus::doublevar) {
		return Var(this->dvar + right.todouble());
	}
	else if (this->status == VarStatus::strvar) {
		return Var(this->strvar + right.toxstring());
	}

	return Var();
}

Var Var::operator - (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return Var(this->ivar - right.toint());
	}
	else if (this->status == VarStatus::doublevar) {
		return Var(this->dvar - right.todouble());
	}
	else if (this->status == VarStatus::strvar) {
		Var tmp(this->todouble() - right.todouble());
		return Var(tmp.toxstring());
	}

	return Var();
}


Var Var::operator += (const Var &right) {
	*this = *this + right;
	return *this;
}

Var Var::operator *= (const Var &right) {
	*this = *this * right;
	return *this;
}

Var Var::operator /= (const Var &right) {
	*this = *this / right;
	return *this;
}

Var Var::operator -= (const Var &right) {
	*this = *this - right;
	return *this;
}


const bool Var::operator > (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return this->ivar > right.toint();
	}
	else if (this->status == VarStatus::doublevar) {
		return this->dvar > right.todouble();
	}
	else if (this->status == VarStatus::strvar) {
		return this->strvar > right.toxstring();
	}

	return false;
}

const bool Var::operator < (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return this->ivar < right.toint();
	}
	else if (this->status == VarStatus::doublevar) {
		return this->dvar < right.todouble();
	}
	else if (this->status == VarStatus::strvar) {
		return this->strvar < right.toxstring();
	}

	return false;
}


const bool Var::operator >= (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return this->ivar >= right.toint();
	}
	else if (this->status == VarStatus::doublevar) {
		return this->dvar >= right.todouble();
	}
	else if (this->status == VarStatus::strvar) {
		return this->strvar >= right.toxstring();
	}

	return false;
}

const bool Var::operator <= (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return this->ivar <= right.toint();
	}
	else if (this->status == VarStatus::doublevar) {
		return this->dvar <= right.todouble();
	}
	else if (this->status == VarStatus::strvar) {
		return this->strvar <= right.toxstring();
	}

	return false;
}


const bool Var::operator != (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return this->ivar != right.toint();
	}
	else if (this->status == VarStatus::doublevar) {
		return this->dvar != right.todouble();
	}
	else if (this->status == VarStatus::strvar) {
		return this->strvar != right.toxstring();
	}

	return false;
}

const bool Var::operator == (const Var &right) {
	if (this->status == VarStatus::intvar) {
		return this->ivar == right.toint();
	}
	else if (this->status == VarStatus::doublevar) {
		return this->dvar == right.todouble();
	}
	else if (this->status == VarStatus::strvar) {
		return this->strvar == right.toxstring();
	}

	return false;
}


std::ostream& operator << (std::ostream& op, const Var &right) {
	if (right.status == VarStatus::intvar) {
		op << right.ivar;
	}
	else if (right.status == VarStatus::doublevar) {
		op << right.dvar;
	}
	else if (right.status == VarStatus::strvar) {
		op << right.strvar.c_str();
	}

	return op;
}

std::istream& operator >> (std::istream& ip, Var &right) {
	if (right.status == VarStatus::intvar) {
		ip >> right.ivar;
	}
	else if (right.status == VarStatus::doublevar) {
		ip >> right.dvar;
	}
	else if (right.status == VarStatus::strvar) {
		char ch[200];
		memset(ch, '\0', 200);
		ip >> ch;
		right.strvar = std::string(ch);
	}

	return ip;
}


const int Var::toint() const {
	if (this->status == VarStatus::intvar) {
		return this->ivar;
	}
	else if (this->status == VarStatus::doublevar) {
		return (int)this->dvar;
	}
	else if (this->status == VarStatus::strvar) {
		return atoi(this->strvar.c_str());
	}
	return 0;
}

const double Var::todouble() const {
	if (this->status == VarStatus::intvar) {
		return (double)this->ivar;
	}
	else if (this->status == VarStatus::doublevar) {
		return this->dvar;
	}
	else if (this->status == VarStatus::strvar) {
		return atof(this->strvar.c_str());
	}
	return 0;
}

const std::string Var::toxstring() const {
	if (this->status == VarStatus::intvar) {
		char str[6] = "";
		_itoa_s(this->ivar, str, 6, 10);
		return std::string(str);
	}
	else if (this->status == VarStatus::doublevar) {
		char ch[80] = "";
		sprintf_s(ch, "%d", this->dvar);
		return std::string(ch);
	}
	else if (this->status == VarStatus::strvar) {
		return this->strvar;
	}
	return std::string();
}

Var &Var::operator [] (const int idx) {
	if (this->check_range(idx)) {
		this->index = idx;
	}
	return *this;
}

Var &Var::operator = (const char &right) {
	if (this->status == VarStatus::intvar) {
		std::string str = this->toxstring();
		str[str.size() - this->index - 1] = right;
		*this = Var(Var(str).toint());
	}
	else if (this->status == VarStatus::doublevar) {
		int whole = (int)this->dvar;
		int fract = (int)((this->dvar - floor(this->dvar)) * pow(10, 3));
		std::string str_whole = Var(whole).toxstring();
		std::string str_fract = Var(fract).toxstring();
		if (this->index >= 0) {
			str_whole[str_whole.size() - this->index - 1] = right;
			*this = Var(Var(str_whole + "." + str_fract).todouble());
		} 
		else {
			int rev_index = -this->index;
			str_fract[str_fract.size() - rev_index - 1] = right;
			*this = Var(Var(str_whole + "." + str_fract).todouble());
		}
	}
	else if (this->status == VarStatus::strvar) {
		this->strvar[this->index] = right;
	}
	return *this;
}

const bool Var::check_range(const int idx) const {
	if (this->status == VarStatus::intvar) {
		std::string str = this->toxstring();
		if (str.size() - 1 < idx) {
			throw std::range_error("Char index is out of range.");
			return false;
		}
		if (idx < 0) {
			throw std::range_error("Char index is above 0.");
			return false;
		}
	}
	else if (this->status == VarStatus::doublevar) {
		int whole = (int)this->dvar;
		int fract = (int)((this->dvar - floor(this->dvar)) * pow(10, 5));
		std::string str_whole = Var(whole).toxstring();
		std::string str_fract = Var(fract).toxstring();
		if (idx >= 0) {
			if (str_whole.size() - 1 < idx) {
				throw std::range_error("Char index is out of range.");
				return false;
			}
		}
		else {
			int rev_index = -idx;
			if (str_fract.size() - 1 < rev_index) {
				throw std::range_error("Char index is out of range.");
				return false;
			}
		}
	}
	else if (this->status == VarStatus::strvar) {
		if (this->strvar.size() - 1 < idx) {
			throw std::range_error("Char index is out of range.");
			return false;
		}
	}

	return true;
}