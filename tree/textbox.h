#pragma once
//这是一个标签库，在定义单击事件后可作为按钮使用
#include "common.h"
#include "rect.h"
#include "cursor.h"
//HWND hwnd ;
class Edit
{
public:
	Edit(int x, int y, int w, int h, COLORREF color);
	/*Edit(int x, int y, int w, int h, string text);*/
	void Show();
	void ClickEvent(ExMessage msg);
	bool InEdit(ExMessage msg);
	void OnEvent(ExMessage msg);
	wstring GetText();

private:
	Rect rect;
	Cursor cursor;
	wstring text;		//存储内容
	int textw;			//文字宽度
	bool inputState;	//是否输入
};
