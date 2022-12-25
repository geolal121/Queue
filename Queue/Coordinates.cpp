#include "Coordinates.h"

void Coordinates::gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
}
void Coordinates::showConsoleCursor(bool showFlag) {
	HANDLE outConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(outConsole, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(outConsole, &cursorInfo);
}
void Coordinates::setColor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}