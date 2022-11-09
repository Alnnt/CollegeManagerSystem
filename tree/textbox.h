#pragma once
//����һ����ǩ�⣬�ڶ��嵥���¼������Ϊ��ťʹ��
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
	wstring text;		//�洢����
	int textw;			//���ֿ��
	bool inputState;	//�Ƿ�����
};
