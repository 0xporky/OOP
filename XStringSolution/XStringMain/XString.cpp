
#include "stdafx.h"
#include "XString.h"

XString::XString() : str('\0'), len(0)
{}

XString::XString(const char *str) {
	this->len = strlen(str) + 1;
	this->str = new char[this->len];
	strcpy_s(this->str, this->len, str);
}

XString::XString(const XString &obj) {
	this->len = obj.len;
	this->str = new char[this->len];
	strcpy_s(this->str, this->len, obj.str);
}

XString::XString(XString&& obj) : str(obj.str)
{ obj.str = nullptr; }

XString::~XString() {
	delete[]this->str;
	this->str = nullptr;
	this->len = 0;
}


const char *XString::get_str() const {
	return this->str;
}


XString& XString::operator = (const XString &right) {
	if (this == &right) {
		return *this;
	}

	this->len = right.len;
	this->str = new char[this->len];
	strcpy_s(this->str, this->len, right.str);
}

XString& XString::operator = (XString &&right) {
	this->str = right.str;
	right.str = nullptr;
	return *this;
}


XString XString::operator * (const XString &right) {
	XString result;
	char tmp[2];
	memset(tmp, '\0', 2);

	char *ch = strpbrk(this->str, right.str);
	while (ch != NULL) {
		tmp[0] = ch[0];
		result += tmp;
		ch = strpbrk(ch + 1, right.str);
	}
	return result;
}

XString& XString::operator *= (const XString &right) {
	*this = *this * right;
	return *this;
}


XString XString::operator / (const XString &right) {
	XString result;
	char tmp[2];
	memset(tmp, '\0', 2);

	for (int i = 0; i < this->len; i++) {
		char * ch = strchr(right.str, this->str[i]);
		if (ch == NULL) {
			tmp[0] = this->str[i];
			result += tmp;
		}
	}
	return result;
}

XString& XString::operator /= (const XString &right) {
	*this = *this / right;
	return *this;
}


XString XString::operator + (const XString &right) {
	XString result;
	result += *this;
	result += right;
	return result;
}

XString operator + (const XString &left, const char *right) {
	XString result;
	result += left;
	result += right;
	return result;
}

XString operator + (const char *left, const XString &right) {
	XString result;
	result += left;
	result += right;
	return result;
}


XString& operator += (XString &left, const XString &right) {
	int new_len = left.len + right.len;
	char *tmp = new char[new_len];

	memset(tmp, '\0', new_len);

	if (left.len != 0) strcpy_s(tmp, left.len, left.str);
	if (right.len != 0) strcat_s(tmp, new_len, right.str);

	delete[] left.str;
	left.str = new char[new_len];
	strcpy_s(left.str, new_len, tmp);
	left.len = new_len;

	delete[] tmp;
	return left;
}

XString& operator += (XString &left, const char *right) {
	int right_len = strlen(right) + 1;
	int new_len   = left.len + right_len;
	char *tmp     = new char[new_len];

	memset(tmp, '\0', new_len);

	if (left.len != 0) strcpy_s(tmp, left.len, left.str);
	if (right_len != 0) strcat_s(tmp, new_len, right);

	delete[] left.str;
	left.str = new char[new_len];
	strcpy_s(left.str, new_len, tmp);
	left.len = new_len;

	delete[] tmp;
	return left;
}


char &XString::operator [] (const int idx) {
	if ((this->len - 2) < idx) {
		return this->str[this->len - 2];
	}
	return this->str[idx];
}

XString XString::operator() (const int idx, const int size) {
	if (idx > this->len - 2) {
		XString s;
		return s;
	}
	char *tmp = new char[size+1];
	strncpy_s(tmp, size+1, &this->str[idx], size);
	tmp[size] = '\0';
	XString s(tmp);
	delete[] tmp;
	return s;
}



bool operator > (const XString &left, const XString &right) {
	return strcmp(left.str, right.str) > 0;
}

bool operator > (const XString &left, const char *right) {
	return strcmp(left.str, right) > 0;
}

bool operator > (const char *left, const XString &right) {
	return strcmp(left, right.str) > 0;
}


bool operator < (const XString &left, const XString &right) {
	return strcmp(left.str, right.str) < 0;
}

bool operator < (const XString &left, const char *right) {
	return strcmp(left.str, right) < 0;
}

bool operator < (const char *left, const XString &right) {
	return strcmp(left, right.str) < 0;
}


bool operator >= (const XString &left, const XString &right) {
	int result = strcmp(left.str, right.str);
	return (result > 0 || result == 0);
}

bool operator >= (const XString &left, const char *right) {
	int result = strcmp(left.str, right);
	return (result > 0 || result == 0);
}

bool operator >= (const char *left, const XString &right) {
	int result = strcmp(left, right.str);
	return (result > 0 || result == 0);
}


bool operator <= (const XString &left, const XString &right) {
	int result = strcmp(left.str, right.str);
	return (result < 0 || result == 0);
}

bool operator <= (const XString &left, const char *right) {
	int result = strcmp(left.str, right);
	return (result < 0 || result == 0);
}

bool operator <= (const char *left, const XString &right) {
	int result = strcmp(left, right.str);
	return (result < 0 || result == 0);
}


bool operator == (const XString &left, const XString &right) {
	return strcmp(left.str, right.str) == 0;
}

bool operator == (const XString &left, const char *right) {
	return strcmp(left.str, right) == 0;
}

bool operator == (const char *left, const XString &right) {
	return strcmp(left, right.str) == 0;
}


bool operator != (const XString &left, const XString &right) {
	return strcmp(left.str, right.str) != 0;
}

bool operator != (const XString &left, const char *right) {
	return strcmp(left.str, right) != 0;
}

bool operator != (const char *left, const XString &right) {
	return strcmp(left, right.str) != 0;
}