#include "button.h"

Button::Button(int x, int y, int w, int h, IMAGE* common, IMAGE* light, IMAGE* press,void (*ClickEvent)(void))
{
    this->x = x;
    this->y = y;
    this->w = common->getwidth();
    this->h = common->getheight();
    this->common = common;
    this->light = light;
    this->press = press;
    this->ClickEvent = ClickEvent;
    this->uiType = UI_COMMON;
}

//void Button::RestoreColor()
//{
//    this->curColor = oldColor;
//}

void Button::Show()
{
       switch (uiType)
       {
        case UI_COMMON:
            //putimage(x, y, common);
            drawAlpha(x, y, common);
            break;
        case UI_LIGHT:
            //putimage(x, y, light);
            drawAlpha(x, y, light);
            break;
        case UI_PRESS:
            //putimage(x, y, press);
            drawAlpha(x, y, press);
            break;
       }

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

void Button::OnEvent(ExMessage msg)
{
    if (InButton(msg))
    {
        switch (msg.message)
        {
        case WM_LBUTTONDOWN:
            uiType = UI_PRESS;
            break;
        case WM_LBUTTONUP:
            (*ClickEvent)();
            uiType = UI_LIGHT;
            break;
        default:
            uiType = UI_LIGHT;
                break;
        }
    }
    else {
        uiType = UI_COMMON;
    }
}