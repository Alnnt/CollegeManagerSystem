#include "includes.h"
#include "textbox.h"

HWND hwnd;

//对于不同的界面，实现选择夹功能
enum TYPE_UI {
	LOGIN_UI,
	REGISTER_UI
};

int main()
{
	TYPE_UI UIinterface = LOGIN_UI;

	IMAGE img_logo;

	IMAGE img_button_login_common;
	IMAGE img_button_login_light;
	IMAGE img_button_login_press;
	
	IMAGE img_button_exit_common;
	IMAGE img_button_exit_light;
	IMAGE img_button_exit_press;

	loadimage(&img_logo, _T("./images\\logo.png"));




	const wstring USER_ACCOUNT = L"admin";			//用户登录账号
	const wstring USER_PASSWORDS = L"123456";			//用户登录密码

	hwnd = initgraph(800, 550);
	setbkcolor(RGB(238, 238, 238));
	cleardevice();
	settextcolor(BLACK);


	settextstyle(20, 0, L"微软雅黑");

	Edit* pTextboxAccount = new Edit(120, 238, 200, 25, RGB(238, 238, 238));  //账号编辑框
	Edit* pTextboxPassword = new Edit(120, 278, 200, 25, RGB(238, 238, 238));  //密码编辑框
	Edit* pEdit3 = new Edit(340, 275, 40, 25, RGB(238, 238, 238));   //登录按钮外框
	Edit* pEdit4 = new Edit(220, 275, 40, 25, RGB(238, 238, 238));   //退出按钮外框
	

	ExMessage msg;    //鼠标消息
	//Edit edit();

	BeginBatchDraw();
	while (true)
	{
		
		while (peekmessage(&msg))
		{
			switch (UIinterface){
				/*     登陆界面     */
			case LOGIN_UI:
				//注册编辑框事件（按键）
				pTextboxAccount->OnEvent(msg);
				pTextboxPassword->OnEvent(msg);

				if (msg.x >= 340 && msg.x <= (340 + 40) && msg.y >= 275 &&
					msg.y <= 300 && msg.message == WM_LBUTTONDOWN) {
					//比较用户输入账号与密码是否正确
					if (pTextboxAccount->GetText() == USER_ACCOUNT && pTextboxPassword->GetText() == USER_PASSWORDS) {
						MessageBox(hwnd, L"登入成功！", L"提示", MB_OKCANCEL);
					}
					else {
						MessageBox(hwnd, L"账号或密码错误", L"错误提示", MB_OKCANCEL);
					}
				}
				//注册鼠标点击事件
				pEdit3->ClickEvent(msg);
				pEdit4->ClickEvent(msg);

				break;
				/*     注册界面     */
			case REGISTER_UI:

				break;
			}
		}

		//渲染
		putimage(0, 0, &img_logo);

		pTextboxAccount->Show();
		pTextboxPassword->Show();
		pEdit3->Show();
		pEdit4->Show();

		outtextxy(70, 240, L"账号：");
		outtextxy(70, 280, L"密码：");
		outtextxy(340, 277, L"登录");
		outtextxy(220, 277, L"退出");
		//Edit edit();


		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	return 0;
}
