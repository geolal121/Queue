#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class Coordinates {
public:
	HANDLE hOutput;
	void gotoxy(int x, int y);
	void showConsoleCursor(bool showFlag);
	void setColor(WORD color);
};