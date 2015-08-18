
#include "stdafx.h"
#include "Screen.h"

Screen::Screen(ScreenType st) {
	this->hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	
	this->draw_frame(csbi.srWindow);
	this->draw_menu(csbi.srWindow);
}

void Screen::draw_frame(SMALL_RECT window_size) {
	char luc = 0xc9; // left upper corner
	char lbc = 0xc8; // left botton corner
	char rup = 0xbb; // right upper corner
	char rbc = 0xbc; // right botton corner
	char vl = 0xba; // vertical line
	char hl = 0xcd; // horisotl line
	COORD pos;

	auto output = [&pos, this](int x, int y, char ch) -> void {
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(this->hCon, pos);
		SetConsoleTextAttribute(this->hCon, FOREGROUND_GREEN);
		if (ch != 0) {
			cout << ch;
		}
	};
	
	output(window_size.Left, window_size.Top, luc);
	output(window_size.Right, window_size.Top, rup);
	output(window_size.Left, window_size.Bottom - 1, lbc);
	output(window_size.Right, window_size.Bottom - 1, rbc);

	for (int i = window_size.Left + 1; i < window_size.Right; ++i) {
		output(i, window_size.Top, hl);
		output(i, window_size.Bottom-1, hl);
	}

	for (int i = window_size.Top + 1; i < window_size.Bottom-1; ++i) {
		output(window_size.Left, i, vl);
		output(window_size.Right, i, vl);
	}

	output(window_size.Left + 1, window_size.Top + 1, 0);
}

void Screen::draw_menu(SMALL_RECT window_size) {
	COORD pos;

	auto output = [&pos, this](int x, int y, string key, string text) -> void {
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(this->hCon, pos);
		SetConsoleTextAttribute(this->hCon, BACKGROUND_RED | BACKGROUND_INTENSITY);
		cout << key.c_str() << " ";
		SetConsoleTextAttribute(this->hCon, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		cout << text.c_str();
	};

	output(window_size.Left + 1, window_size.Bottom, string("F1"), string("Open"));
}