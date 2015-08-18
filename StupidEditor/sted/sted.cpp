// sted.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Screen.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Screen sr(ScreenType::EDITOR);

	getchar();

	return EXIT_SUCCESS;
}

