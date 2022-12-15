#pragma once
//这是一个标签库，在定义单击事件后可作为按钮使用   **已废弃**
// 
//现在为编辑框库
#include "common.h"
#include "rect.h"
#include "cursor.h"
//HWND hwnd ;
enum inType{
	INPUT_COMMON,
	INPUT_PASSOWRD
};

class Textbox
{
public:
	Textbox(int x, int y, int w, int h, COLORREF color,inType inputType = INPUT_COMMON);
	/*Textbox(int x, int y, int w, int h, string text);*/
	void Show();
	void ClickEvent(ExMessage& msg);
	bool InEdit(ExMessage& msg);
	void OnEvent(ExMessage& msg);
	wstring GetText();
	void ClearText();
	void SetText(LPCTSTR text);
private:
	Rect rect;
	Cursor cursor;
	wstring text;		//存储内容
	int textw;			//文字宽度
	bool inputState;	//是否输入
	wstring hideText;   //匹配密码编辑框模式
	int hideTextw;      //密码模式文字宽度
	inType inputType;   //文本输入方式
};
