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
Edit::Edit(int x, int y, int w, int h, COLORREF color) :rect(x, y, w, h, color), cursor(x, y, 1, h - 4, color)
{
    this->inputState = false;
    this->textw = 0;
}


void Edit::Show()
{
    rect.Show();        //����
    //��������
    setbkmode(TRANSPARENT); //���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ -> ͸��
    settextcolor(BLACK);
    textw = textwidth(text.c_str());
    outtextxy(rect.GetX() + 10, rect.GetY() + 5, text.c_str());
    //settextstyle(20, 0, L"΢���ź�");
    //outtextxy(135, 100, L"�˺ţ�");
    //outtextxy(135, 200, L"���룺");
    //outtextxy(340, 277, L"��¼");
    //outtextxy(220, 277, L"�˳�");
    //���
    if (inputState == true)
    {
        cursor.SetCurSor(rect.GetX() + textw + 10, rect.GetY() + 2);
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
                }
                break;
            case '\r':                  //���»س���ȷ������
            case '\n':
                rect.RestoreColor();
                inputState = false;
                break;
            default:                    //�����ַ�
                text.push_back(msg.ch);
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
