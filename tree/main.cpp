#include "includes.h"
#include "manager.h"
#include "data.h"

/// <summary>
///	窗口无边框并圆角化
/// </summary>
/// <param name="radius">圆角半径</param>
void enRoundWindows(int radius);

HWND hwnd;
//Json::Value listData;

//设置当前界面为登录界面，对于不同的界面，实现选择夹功能
TYPE_UI UIinterface = LOGIN_UI;

//注册控件
Edit* pTextboxAccount;
Edit* pTextboxPassword;
Button* pButtonClose;
Button* pButtonLogin;
Button* pButtonRegister;
Button* pButtonXueshenghui;
Button* pButtonShelian;
Button* pButtonGechuang;

listTable* pListTable;


int main()
{
	/*  加载图像资源  */
	IMAGE img_logo;
	IMAGE img_button_close_common;
	IMAGE img_button_close_light;
	IMAGE img_button_close_press;

	IMAGE img_button_login_common;
	IMAGE img_button_login_light;
	IMAGE img_button_login_press;

	IMAGE img_button_register_common;
	IMAGE img_button_register_light;
	IMAGE img_button_register_press;

	IMAGE img_bk_manager;
	IMAGE img_chosen_insitution;
	IMAGE img_chosen_department;
	IMAGE img_lighter_department;

	IMAGE img_button_xueshenghui_common;
	IMAGE img_button_xueshenghui_light;
	IMAGE img_button_xueshenghui_press;
	IMAGE img_button_shelian_common;
	IMAGE img_button_shelian_light;
	IMAGE img_button_shelian_press;
	IMAGE img_button_gechuang_common;
	IMAGE img_button_gechuang_light;
	IMAGE img_button_gechuang_press;


	loadimage(&img_logo, _T("./images\\logo.png"));
	loadimage(&img_button_close_common, _T("./images\\button_close_common.png"));
	loadimage(&img_button_close_light, _T("./images\\button_close_light.png"));
	loadimage(&img_button_close_press, _T("./images\\button_close_press.png"));
	loadimage(&img_button_login_common, _T("./images\\button_login_common.png"));
	loadimage(&img_button_login_light, _T("./images\\button_login_light.png"));
	loadimage(&img_button_login_press, _T("./images\\button_login_press.png"));
	loadimage(&img_button_register_common, _T("./images\\button_register_common.png"));
	loadimage(&img_button_register_light, _T("./images\\button_register_light.png"));
	loadimage(&img_button_register_press, _T("./images\\button_register_press.png"));

	loadimage(&img_bk_manager, _T("./images\\bk_manager.png"));
	loadimage(&img_button_xueshenghui_common, _T("./images\\button_xueshenghui_common.png"));
	loadimage(&img_button_xueshenghui_light, _T("./images\\button_xueshenghui_light.png"));
	loadimage(&img_button_xueshenghui_press, _T("./images\\button_xueshenghui_press.png"));
	loadimage(&img_button_shelian_common, _T("./images\\button_shelian_common.png"));
	loadimage(&img_button_shelian_light, _T("./images\\button_shelian_light.png"));
	loadimage(&img_button_shelian_press, _T("./images\\button_shelian_press.png"));
	loadimage(&img_button_gechuang_common, _T("./images\\button_gechuang_common.png"));
	loadimage(&img_button_gechuang_light, _T("./images\\button_gechuang_light.png"));
	loadimage(&img_button_gechuang_press, _T("./images\\button_gechuang_press.png"));

	loadimage(&img_chosen_insitution, _T("./images\\chosen_insitution.png"));

	/*  加载配置资源  */
	//用户信息
	const wstring USER_ACCOUNT = L"admin";			//用户登录账号
	const wstring USER_PASSWORDS = L"123456";			//用户登录密码

	//json数据库
	ifstream fin("data/data.json");
	Json::Reader reader;
	Json::Value data;
	reader.parse(fin, data, 0);
	using namespace std;
	cout << data["xueshenghui"].toStyledString() << endl;
	//initJsonDB("data/data.json");
	

	/*  初始化窗体绘图空间  */
	hwnd = initgraph(1280, 768, EX_SHOWCONSOLE); //EX_SHOWCONSOLE
	setbkcolor(RGB(238, 238, 238));
	cleardevice();
	settextcolor(BLACK);

	enRoundWindows(25); //窗口无边框并圆角化

	/*  注册控件  */
	pTextboxAccount = new Edit(200, 330, 320, 35, RGB(238, 238, 238), INPUT_COMMON);  //账号编辑框
	pTextboxPassword = new Edit(200, 400, 320, 35, RGB(238, 238, 238), INPUT_PASSOWRD);  //密码编辑框
	pButtonClose = new Button(1236, 2, 0, 0, &img_button_close_common, &img_button_close_light, &img_button_close_press, _CLOSE_onClick);   //关闭按钮
	pButtonLogin = new Button(350, 470, 0, 0, &img_button_login_common, &img_button_login_light, &img_button_login_press, _LOGIN_onClick);   //登录按钮外框
	pButtonRegister = new Button(150, 470, 0, 0, &img_button_register_common, &img_button_register_light, &img_button_register_press, _REGISTER_onClick);   //注册按钮外框
	pButtonXueshenghui = new Button(180, 17, 0, 0, &img_button_xueshenghui_common, &img_button_xueshenghui_light, &img_button_xueshenghui_press, _XSH_onClick);//学生会机构按钮
	pButtonShelian = new Button(600, 17, 0, 0, &img_button_shelian_common, &img_button_shelian_light, &img_button_shelian_press, _SL_onClick);//社联机构按钮
	pButtonGechuang= new Button(1000, 17, 0, 0, &img_button_gechuang_common, &img_button_gechuang_light, &img_button_gechuang_press, _GC_onClick);//格创机构按钮

	pListTable = new listTable(data["xueshenghui"][0]["agents"], 265, 180, 30, 60, 190, 320, 520);    //列表框

	/*  注册热键  */




	ExMessage msg;

	/*  开始绘制  */
	BeginBatchDraw();
	while (true)
	{
		while (peekmessage(&msg))
		{
			if (msg.y < 30 && msg.x < 1236 && msg.message == WM_LBUTTONDOWN) {
				SendMessage(hwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);   //窗口随意拖拽
			}

			pButtonClose->OnEvent(msg);

			switch (UIinterface){
				/*     登陆界面     */
			case LOGIN_UI:
				//注册事件
				pButtonLogin->OnEvent(msg);
				pButtonRegister->OnEvent(msg);
				pTextboxAccount->OnEvent(msg);
				pTextboxPassword->OnEvent(msg);
				//----------------------------------------------------------------
				//if (msg.x >= 340 && msg.x <= (340 + 40) && msg.y >= 275 &&
				//	msg.y <= 300 && msg.message == WM_LBUTTONDOWN) {
				//	//比较用户输入账号与密码是否正确
				//	if (pTextboxAccount->GetText() == USER_ACCOUNT && pTextboxPassword->GetText() == USER_PASSWORDS) {
				//		MessageBox(hwnd, L"登入成功！", L"提示", MB_OKCANCEL);
				//	}
				//	else {
				//		MessageBox(hwnd, L"账号或密码错误", L"错误提示", MB_OKCANCEL);
				//	}
				//}
				//注册鼠标点击事件 （老旧）
				//pEdit3->ClickEvent(msg);
				//pEdit4->ClickEvent(msg);
				
				//渲染
				putimage(0, 0, &img_logo);

				pTextboxAccount->Show();
				pTextboxPassword->Show();
				pButtonLogin->Show();
				pButtonRegister->Show();

				settextstyle(30, 0, L"微软雅黑");
				settextcolor(RGB(14, 206, 234));
				outtextxy(140, 335, L"账号：");
				outtextxy(140, 405, L"密码：");
				//Edit edit();

				break;
				/*     注册界面     */
			case REGISTER_UI:
				putimage(0, 0, &img_logo);

				break;
				/*     管理界面     */
			case MANEGER_UI:
				//注册事件
				pButtonXueshenghui->OnEvent(msg);
				pButtonShelian->OnEvent(msg);
				pButtonGechuang->OnEvent(msg);
				//渲染
				putimage(0, 0, &img_bk_manager);
				
				pButtonXueshenghui->Show();
				pButtonShelian->Show();
				pButtonGechuang->Show();
				pListTable->Show();

				settextstyle(30, 0, L"微软雅黑");
				settextcolor(RGB(7, 7, 152));

				drawInstitutionChosen(&img_chosen_insitution);
				break;
			}
			pButtonClose->Show();
		}

		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	return 0;
}

void enRoundWindows(int radius) {
	//设置程序的显示大小及位置
	MoveWindow(hwnd, 100, 100, 1280, 768, false);

	RECT windowsRC;
	GetWindowRect(hwnd, &windowsRC);

	int scrWidth, scrHeight;
	scrWidth = GetSystemMetrics(SM_CXSCREEN);
	scrHeight = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(hwnd, HWND_TOP, (scrWidth - windowsRC.right) / 2, (scrHeight - windowsRC.bottom) / 2, windowsRC.right - windowsRC.left, windowsRC.bottom - windowsRC.top, SWP_SHOWWINDOW);
	//去除边框
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~(WS_CAPTION | WS_SIZEBOX));
	//窗口圆角化
	HRGN hRgn = CreateRoundRectRgn(0, 0, windowsRC.right - windowsRC.left, windowsRC.bottom - windowsRC.top, radius, radius);
	SetWindowRgn(hwnd, hRgn, true);
}