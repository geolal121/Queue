#include "MyRectangle.h"

MyRectangle::MyRectangle() {
	m_x = m_y = m_w = m_h = 0;
	m_symbol = ' ';
	m_hollow = true;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	m_textColor;
	m_recColor = 15;
	m_sleepTime = 250;
}
MyRectangle::MyRectangle(int xx, int yy, int ww, int hh, char symbol, bool hollow, int recCol, int txtCol, std::string txt, int sleepTime) :MyRectangle() {
	m_x = xx; m_y = yy; m_w = ww; m_h = hh; m_symbol = symbol; m_hollow = hollow; m_recColor = recCol; m_text = txt, m_textColor = txtCol; m_sleepTime = sleepTime;
}
void MyRectangle::setSleepTime(int s) {
	m_sleepTime = s;
}
void MyRectangle::Draw(int x, int y, int w, int h, int symbol, int color, std::string txt) {
	SetConsoleTextAttribute(hConsole, color);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			gotoxy(x + j, y + i);
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				std::cout << char(symbol);
		}
	}
	// draw the text if there is one, in the center
	if (txt != "") {
		SetConsoleTextAttribute(hConsole, 15);
		int textLen = txt.length();
		int midHeight = h / 2;
		int midWidth = w / 2;
		midWidth = midWidth - (textLen / 2);
		gotoxy(x + midWidth, y + midHeight);
		std::cout << txt;
	}
}
void MyRectangle::DrawSkelaton(int x, int y, int w, int h, std::string txt, WORD color, WORD boxColor) {
	SetConsoleTextAttribute(hConsole, boxColor);
	// draw corners.
	gotoxy(x, y);
	std::cout << char(218);
	gotoxy(x + w, y);
	std::cout << char(191);
	gotoxy(x, y + h);
	std::cout << char(192);
	gotoxy(x + w, y + h);
	std::cout << char(217);
	for (int i = x + 1; i < x + w; i++) {
		gotoxy(i, y);
		std::cout << char(196);
		gotoxy(i, y + h);
		std::cout << char(196);
	}
	for (int i = y + 1; i < y + h; i++) {
		gotoxy(x, i);
		std::cout << char(179);
		gotoxy(x + w, i);
		std::cout << char(179);
	}
	if (txt != "") {
		SetConsoleTextAttribute(hConsole, color);
		int textLen = txt.length();
		int midHeight = h / 2;
		int midWidth = w / 2;
		midWidth = midWidth - (textLen / 2);
		gotoxy(x + midWidth + 1, y + midHeight);
		std::cout << txt;
	}
}
void MyRectangle::Draw() {
	SetConsoleTextAttribute(hConsole, m_recColor);
	for (int i = 0; i < m_h; i++) {
		for (int j = 0; j < m_w; j++) {
			gotoxy(m_x + j, m_y + i);
			if (m_hollow) {
				if (i == 0 || i == m_h - 1 || j == 0 || j == m_w - 1)
					std::cout << m_symbol;
			}
			else
				std::cout << m_symbol;
		}
	}
	// draw the text if there is one, in the center
	if (m_text != "") {
		SetConsoleTextAttribute(hConsole, m_textColor);
		int textLen = m_text.length();
		int midHeight = m_h / 2;
		int midWidth = m_w / 2;
		midWidth = midWidth - (textLen / 2);
		gotoxy(m_x + midWidth, m_y + midHeight);
		std::cout << m_text;
	}
}
void MyRectangle::SetX(int xx) {
	m_x = xx;
}
void MyRectangle::SetY(int yy) {
	m_y = yy;
}
void MyRectangle::setWidth(int ww) {
	m_w = ww;
}
void MyRectangle::setHeight(int hh) {
	m_h = hh;
}
void MyRectangle::setSymbol(char cc) {
	m_symbol = cc;
}
void MyRectangle::setHollow(bool h) {
	m_hollow = h;
}
void MyRectangle::setRectangleColor(int colr) {
	m_recColor = colr;
}
void MyRectangle::setTextColor(int colr) {
	m_textColor = colr;
}
void MyRectangle::setText(std::string txt) {
	m_text = txt;
}
void MyRectangle::EraseBox() {
	MyRectangle BlackBox(m_x, m_y, m_w, m_h, ' ', false, 0, 0, "");
	BlackBox.Draw();
}
void MyRectangle::DrawPath(std::string path) {
	char direction;
	std::string s;
	int steps;
	//R5D3R5U6L2
	for (int i = 0; i < path.length(); i += 3) {
		direction = path[i];
		s = path.substr(i + 1, 2);
		steps = stoi(s);
		if (direction == 'R') {
			for (int i = 0; i < steps; i++) {
				EraseBox();
				m_x++;
				Draw();
				Sleep(m_sleepTime);
			}
		}
		else if (direction == 'L') {
			for (int i = 0; i < steps; i++) {
				EraseBox();
				m_x--;
				Draw();
				Sleep(m_sleepTime);
			}
		}
		else if (direction == 'D') {
			for (int i = 0; i < steps; i++) {
				EraseBox();
				m_y++;
				Draw();
				Sleep(m_sleepTime);
			}
		}
		else if (direction == 'U') {
			for (int i = 0; i < steps; i++) {
				EraseBox();
				m_y--;
				Draw();
				Sleep(m_sleepTime);
			}
		}
	}
}
void MyRectangle::Impolode() {
	// to erase the text at the end after the zoom in is complete
	MyRectangle M(m_x, m_y, m_w, m_h, ' ', true, 0, 0, "", 0);
	while (m_w > 1 && m_h > 1) {
		EraseBox();
		if (m_w - 1 >= 0)
			m_w--;
		if (m_h - 1 >= 0)
			m_h--;
		Draw();
		Sleep(m_sleepTime);
	}
	//EraseBox();
	M.Draw();
}