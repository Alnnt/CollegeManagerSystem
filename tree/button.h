#pragma once
#include "common.h"
#include "VisualEffects.h"



class Button
{
public:
	//Button(int x = 0, int y = 0, int w = EDIT_W, int h = EDIT_H, COLORREF = RGB(238, 238, 238));
	Button(int x, int y, int w, int h, IMAGE* common, IMAGE* light, IMAGE* press, void (*ClickEvent)(void));
	void Show();
	bool InButton(ExMessage& msg);
	void OnEvent(ExMessage& msg);
private:
	int x;
	int y;
	int w;
	int h;
	IMAGE* common;
	IMAGE* light;
	IMAGE* press;
	void (*ClickEvent)(void);
	uiType uiType;
	//COLORREF curColor;
	//COLORREF oldColor;
};
