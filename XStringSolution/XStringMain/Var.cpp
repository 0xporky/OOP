
#include "stdafx.h"
#include "Var.h"

Var::Var() : ivar(0), status(VarStatus::intvar)
{}

Var::Var(int var) : ivar(var), status(VarStatus::intvar)
{}

Var::Var(double var) : dvar(var), status(VarStatus::doublevar)
{}

Var::Var(XString var) : xsvar(var.get_str()), status(VarStatus::xstrvar)
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
	case VarStatus::xstrvar:
		this->xsvar = obj.xsvar;
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
	else if (this->status == VarStatus::xstrvar) {
		return Var(this->xsvar * right.toxstring());
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
	else if (this->status == VarStatus::xstrvar) {
		return Var(this->xsvar / right.toxstring());
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
	else if (this->status == VarStatus::xstrvar) {
		return Var(this->xsvar + right.toxstring());
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
	else if (this->status == VarStatus::xstrvar) {
		return Var(this->xsvar / right.toxstring());
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
	else if (this->status == VarStatus::xstrvar) {
		return this->xsvar > right.toxstring();
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
	else if (this->status == VarStatus::xstrvar) {
		return this->xsvar < right.toxstring();
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
	else if (this->status == VarStatus::xstrvar) {
		return this->xsvar >= right.toxstring();
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
	else if (this->status == VarStatus::xstrvar) {
		return this->xsvar <= right.toxstring();
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
	else if (this->status == VarStatus::xstrvar) {
		return this->xsvar != right.toxstring();
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
	else if (this->status == VarStatus::xstrvar) {
		return this->xsvar == right.toxstring();
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
	else if (right.status == VarStatus::xstrvar) {
		op << right.xsvar.get_str();
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
	else if (right.status == VarStatus::xstrvar) {
		char ch[200];
		memset(ch, '\0', 200);
		ip >> ch;
		right.xsvar = XString(ch);
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
	else if (this->status == VarStatus::xstrvar) {
		return atoi(this->xsvar.get_str());
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
	else if (this->status == VarStatus::xstrvar) {
		return atof(this->xsvar.get_str());
	}
	return 0;
}

const XString Var::toxstring() const {
	if (this->status == VarStatus::intvar) {
		char str[6] = "";
		_itoa_s(this->ivar, str, 6, 10);
		return XString(str);
	}
	else if (this->status == VarStatus::doublevar) {
		char ch[80] = "";
		sprintf_s(ch, "%d", this->dvar);
		return XString(ch);
	}
	else if (this->status == VarStatus::xstrvar) {
		return this->xsvar;
	}
	return XString();
}