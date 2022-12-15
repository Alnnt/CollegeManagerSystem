#pragma once
#include "common.h"
class Rect
{
public:
	Rect(int x = 0, int y = 0, int w = EDIT_W, int h = EDIT_H, COLORREF = RGB(238, 238, 238));
	int GetX();
	int GetY();
	int GetW();
	int GetH();
	int GetColor();
	void SetColor(COLORREF color);
	void SetX(int x);
	void SetY(int y);
	void SetW(int w);
	void SetH(int h);
	void RestoreColor();		//»¹Ô­ÑÕÉ«
	void Show();
	bool InRect(ExMessage msg);
private:
	int x;
	int y;
	int w;
	int h;

	COLORREF curColor;
	COLORREF oldColor;
};
