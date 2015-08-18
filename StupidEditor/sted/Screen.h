#pragma once

#include <Windows.h>
#include <iostream>
#include "ScreenTypes.h"

using namespace std;

class Screen {
public:
	Screen(ScreenType st);

private:
	HANDLE hCon;

	void draw_frame(SMALL_RECT window_size);
	void draw_menu(SMALL_RECT window_size);
};
