#include "rect.h"
Rect::Rect(int x, int y, int w, int h, COLORREF color)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->curColor = color;
    this->oldColor = color;
}
int Rect::GetX()
{
    return x;
}

int Rect::GetY()
{
    return y;
}

int Rect::GetW()
{
    return w;
}

int Rect::GetH()
{
    return h;
}

int Rect::GetColor()
{
    return curColor;
}

void Rect::SetColor(COLORREF color)
{
    this->curColor = color;
}

void Rect::SetX(int x)
{
    this->x = x;
}

void Rect::SetY(int y)
{
    this->y = y;
}

void Rect::SetW(int w)
{
    this->w = w;
}

void Rect::SetH(int h)
{
    this->h = h;
}

void Rect::RestoreColor()
{
    this->curColor = oldColor;
}

void Rect::Show()
{
    setfillcolor(this->curColor);
    setlinecolor(BLACK);
    fillrectangle(x, y, x + w, y + h);

}
/// <summary>
/// �ж�����Ƿ��ھ�����
/// </summary>
/// <param name="msg">�����Ϣ</param>
/// <returns>true - ��\n false - ����</returns>
bool Rect::InRect(ExMessage msg)
{
    if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
    {
        return true;
            //�ж�����Ƿ����˳���ť��
            //if (msg.x >= 220 && msg.x < +220 + 40 && msg.y >= 275 && msg.y <= 300) {
            //    Sleep(3000);
            //    exit(1);
            //    return false;
            //}
    }
    return false;
    //return (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h) ;
}

