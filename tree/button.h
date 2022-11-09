#pragma once
#include "common.h"
class Button
{
public:
	//Button(int x = 0, int y = 0, int w = EDIT_W, int h = EDIT_H, COLORREF = RGB(238, 238, 238));
	Button(int x, int y, int w, int h, IMAGE* common, IMAGE* light, IMAGE* press);
	int GetX();
	int GetY();
	int GetW();
	int GetH();
	void SetX(int x);
	void SetY(int y);
	void SetW(int w);
	void SetH(int h);
	void Show(ExMessage msg);
	bool InButton(ExMessage msg);
private:
	int x;
	int y;
	int w;
	int h;
	IMAGE* common;
	IMAGE* light;
	IMAGE* press;
	//COLORREF curColor;
	//COLORREF oldColor;
};
