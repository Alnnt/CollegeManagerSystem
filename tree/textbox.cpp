#include "textbox.h"
extern HWND hwnd;
/// <summary>
/// ����༭��/��ǩ
/// </summary>
/// <param name="x">���</param>
/// <param name="y">����</param>
/// <param name="w">���</param>
/// <param name="h">�߶�</param>
/// <param name="color">Ĭ�ϱ�����ɫ</param>
Edit::Edit(int x, int y, int w, int h, COLORREF color,inType inputType) :rect(x, y, w, h, color), cursor(x, y, 1, h - 4, color)
{
    this->inputState = false;
    this->textw = 0;
    this->inputType = inputType;
    this->hideTextw = 0;
}


void Edit::Show()
{
    rect.Show();        //����
    //��������
    setbkmode(TRANSPARENT); //���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ -> ͸��
    settextcolor(BLACK);
    textw = textwidth(text.c_str());
    if (inputType == INPUT_PASSOWRD) {
        hideTextw = textwidth(hideText.c_str());
    }
    switch (inputType)
    {
    case INPUT_COMMON:
        outtextxy(rect.GetX() + 10, rect.GetY() + 5, text.c_str());
        break;
    case INPUT_PASSOWRD:
        outtextxy(rect.GetX() + 10, rect.GetY() + 5, hideText.c_str());
        break;
    }
    //���
    if (inputState == true)
    {
        switch (inputType)
        {
        case INPUT_COMMON:
            cursor.SetCurSor(rect.GetX() + textw + 10, rect.GetY() + 2);
            break;
        case INPUT_PASSOWRD:
            //wstring hide = L"*";
            cursor.SetCurSor(rect.GetX() + hideTextw + 10, rect.GetY() + 2);
            break;
        }
        //cursor.SetCurSor(rect.GetX() + textw + 10, rect.GetY() + 2);
        cursor.Show();
    }
}

void Edit::ClickEvent(ExMessage msg)
{
    //�ж�����Ƿ����˳���ť��   �����������ť
    if (msg.x >= 220 && msg.x < +220 + 40 && msg.y >= 275 &&
        msg.y <= 300 && msg.message == WM_LBUTTONDOWN) {

        MessageBox(hwnd, L"��ȷ��Ҫ�˳���", L"��ʾ", MB_OKCANCEL);
    }
    //�ж�����Ƿ��ڵ�¼��ť����  ���������

}

bool Edit::InEdit(ExMessage msg)
{
    return rect.InRect(msg);
}

void Edit::OnEvent(ExMessage msg)
{
    switch (msg.message)
    {
    case WM_LBUTTONDOWN:            //�����Ϣ
        if (InEdit(msg)) //������ڱ༭�Χ�ڣ���ȡ����
        {
            rect.SetColor(WHITE);
            inputState = true;      //����༭�򣬱༭״̬��Ϊ�ɱ༭״̬
        }
        else             //������ڱ༭�Χ�ڣ�ʧȥ����
        {
            rect.RestoreColor();    //��ԭ��ɫ
            inputState = false;
        }
        break;
    case WM_CHAR:                   //����������ַ���Ϣ
        if (inputState == true)     //һ���ǿ�����״̬
        {
            switch (msg.ch)
            {
            case '\b':              //ɾ��
                if (!text.empty())
                {
                    text.pop_back();    //�ַ���β��ɾ��
                    if (inputType == INPUT_PASSOWRD) {   //****
                        hideText.pop_back();
                    }
                }
                break;
            case '\r':                  //���»س���ȷ������
            case '\n':
                rect.RestoreColor();
                inputState = false;
                break;
            default:                    //�����ַ�
                text.push_back(msg.ch);
                if (inputType == INPUT_PASSOWRD) {   //****
                    hideText.push_back(L'*');
                }
                break;
            }
        }
        break;
    }
}
wstring Edit::GetText()
{
    return text;
}
