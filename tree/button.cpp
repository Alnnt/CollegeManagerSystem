#include "button.h"
Button::Button(int x, int y, int w, int h, IMAGE* common, IMAGE* light, IMAGE* press)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->common = common;
    this->light = light;
    this->press = press;
}
int Button::GetX()
{
    return x;
}

int Button::GetY()
{
    return y;
}

int Button::GetW()
{
    return w;
}

int Button::GetH()
{
    return h;
}


void Button::SetX(int x)
{
    this->x = x;
}

void Button::SetY(int y)
{
    this->y = y;
}

void Button::SetW(int w)
{
    this->w = w;
}

void Button::SetH(int h)
{
    this->h = h;
}

//void Button::RestoreColor()
//{
//    this->curColor = oldColor;
//}

void Button::Show(ExMessage msg)
{
    if(msg.message == WM_LBUTTONDOWN)
        switch (msg.message)
        {
        case WM_LBUTTONDOWN:

            break;
        default:
            putimage(x, y, light);
            break;
        }
    //setfillcolor(this->curColor);
    //setlinecolor(BLACK);
    //fillrectangle(x, y, x + w, y + h);

}
/// <summary>
/// 判断鼠标是否在矩形内
/// </summary>
/// <param name="msg">鼠标消息</param>
/// <returns>true - 在\n false - 不在</returns>
bool Button::InButton(ExMessage msg)
{
    if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
    {
        return true;
    }
    return false;
}

