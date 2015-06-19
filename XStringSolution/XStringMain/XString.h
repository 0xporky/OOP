
#pragma once

#include <cstring>

class XString {
public:
	XString();
	XString(const char *str);
	XString(const XString &obj);

	XString(XString&& obj);

	~XString();

	XString& operator = (const XString &right);
	XString& operator = (XString &&right);

	XString operator * (const XString &right);
	XString operator / (const XString &right);
	XString operator + (const XString &right);

	friend XString operator + (const XString &left, const char *right);
	friend XString operator + (const char *left, const XString &right);

	XString& operator *= (const XString &right);
	XString& operator /= (const XString &right);

	friend XString& operator += (XString &left, const XString &right);
	friend XString& operator += (XString &left, const char *right);

	friend bool operator > (const XString &left, const XString &right);
	friend bool operator > (const XString &left, const char *right);
	friend bool operator > (const char *left, const XString &right);

	friend bool operator < (const XString &left, const XString &right);
	friend bool operator < (const XString &left, const char *right);
	friend bool operator < (const char *left, const XString &right);

	friend bool operator >= (const XString &left, const XString &right);
	friend bool operator >= (const XString &left, const char *right);
	friend bool operator >= (const char *left, const XString &right);

	friend bool operator <= (const XString &left, const XString &right);
	friend bool operator <= (const XString &left, const char *right);
	friend bool operator <= (const char *left, const XString &right);

	friend bool operator != (const XString &left, const XString &right);
	friend bool operator != (const XString &left, const char *right);
	friend bool operator != (const char *left, const XString &right);

	friend bool operator == (const XString &left, const XString &right);
	friend bool operator == (const XString &left, const char *right);
	friend bool operator == (const char *left, const XString &right);

	char &operator [] (const int idx);
	XString operator() (const int idx, const int size);

	const char *get_str() const;

private:
	char *str;
	int len;
};