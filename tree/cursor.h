#pragma once
#include "rect.h"
#include "timer.h"
class Cursor
{
public:
	Cursor(int x, int y, int w, int h, COLORREF color);
	void Show();
	void SetCurSor(int x, int y);
private:
	void Draw();
	void Clear();
private:

	Rect cursor;
	Timer timer;
	int count;			//¿ØÖÆ»æÖÆ
};
