#pragma once
//����һ����ǩ�⣬�ڶ��嵥���¼������Ϊ��ťʹ��   **�ѷ���**
// 
//����Ϊ�༭���
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
	wstring text;		//�洢����
	int textw;			//���ֿ��
	bool inputState;	//�Ƿ�����
	wstring hideText;   //ƥ������༭��ģʽ
	int hideTextw;      //����ģʽ���ֿ��
	inType inputType;   //�ı����뷽ʽ
};
