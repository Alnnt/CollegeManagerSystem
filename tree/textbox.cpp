#include "textbox.h"
extern HWND hwnd;
/// <summary>
/// 构造编辑框/标签
/// </summary>
/// <param name="x">左边</param>
/// <param name="y">顶边</param>
/// <param name="w">宽度</param>
/// <param name="h">高度</param>
/// <param name="color">默认背景颜色</param>
Textbox::Textbox(int x, int y, int w, int h, COLORREF color,inType inputType) :rect(x, y, w, h, color), cursor(x, y, 1, h - 4, color)
{
    this->inputState = false;
    this->textw = 0;
    this->inputType = inputType;
    this->hideTextw = 0;
}


void Textbox::Show()
{
    rect.Show();        //矩形
    //处理文字
    setbkmode(TRANSPARENT); //设置当前设备图案填充和文字输出时的背景模式 -> 透明
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
    //光标
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

void Textbox::ClickEvent(ExMessage& msg)
{
    //判断鼠标是否在退出按钮中   且左键单击按钮
    if (msg.x >= 220 && msg.x < +220 + 40 && msg.y >= 275 &&
        msg.y <= 300 && msg.message == WM_LBUTTONDOWN) {

        MessageBox(hwnd, L"你确定要退出吗？", L"提示", MB_OKCANCEL);
    }
    //判断鼠标是否在登录按钮里面  且左键单击

}

bool Textbox::InEdit(ExMessage& msg)
{
    return rect.InRect(msg);
}

void Textbox::OnEvent(ExMessage& msg){
    switch (msg.message){
    case WM_LBUTTONDOWN:            //鼠标消息
        if (InEdit(msg)){ //当鼠标在编辑款范围内，获取焦点
            rect.SetColor(WHITE);
            inputState = true;      //点击编辑框，编辑状态改为可编辑状态
        }
        else{             //当鼠标在编辑款范围内，失去焦点
            rect.RestoreColor();    //还原颜色
            inputState = false;
        }
        break;
    case WM_CHAR:                   //按键输入的字符消息
        if (inputState == true){     //一定是可输入状态
            switch (msg.ch)
            {
            case '\b':              //删除
                if (!text.empty()){
                    text.pop_back();    //字符串尾部删除
                    if (inputType == INPUT_PASSOWRD) {   //****
                        hideText.pop_back();
                    }
                }
                break;
            case '\r':                  //按下回车，确认输入
            case '\n':
                rect.RestoreColor();
                inputState = false;
                break;
            default:                    //其他字符
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

wstring Textbox::GetText()
{
    return text;
}

void Textbox::ClearText()
{
    text.clear();
}

void Textbox::SetText(LPCTSTR newText) {
    text.clear();
    text.append(newText);
}