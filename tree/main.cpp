#include "includes.h"
#include "manager.h"
#include "data.h"

/// <summary>
///	�����ޱ߿�Բ�ǻ�
/// </summary>
/// <param name="radius">Բ�ǰ뾶</param>
void enRoundWindows(int radius);

HWND hwnd;
//Json::Value listData;

//���õ�ǰ����Ϊ��¼���棬���ڲ�ͬ�Ľ��棬ʵ��ѡ��й���
TYPE_UI UIinterface = LOGIN_UI;

//ע��ؼ�
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
	/*  ����ͼ����Դ  */
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

	/*  ����������Դ  */
	//�û���Ϣ
	const wstring USER_ACCOUNT = L"admin";			//�û���¼�˺�
	const wstring USER_PASSWORDS = L"123456";			//�û���¼����

	//json���ݿ�
	ifstream fin("data/data.json");
	Json::Reader reader;
	Json::Value data;
	reader.parse(fin, data, 0);
	using namespace std;
	cout << data["xueshenghui"].toStyledString() << endl;
	//initJsonDB("data/data.json");
	

	/*  ��ʼ�������ͼ�ռ�  */
	hwnd = initgraph(1280, 768, EX_SHOWCONSOLE); //EX_SHOWCONSOLE
	setbkcolor(RGB(238, 238, 238));
	cleardevice();
	settextcolor(BLACK);

	enRoundWindows(25); //�����ޱ߿�Բ�ǻ�

	/*  ע��ؼ�  */
	pTextboxAccount = new Edit(200, 330, 320, 35, RGB(238, 238, 238), INPUT_COMMON);  //�˺ű༭��
	pTextboxPassword = new Edit(200, 400, 320, 35, RGB(238, 238, 238), INPUT_PASSOWRD);  //����༭��
	pButtonClose = new Button(1236, 2, 0, 0, &img_button_close_common, &img_button_close_light, &img_button_close_press, _CLOSE_onClick);   //�رհ�ť
	pButtonLogin = new Button(350, 470, 0, 0, &img_button_login_common, &img_button_login_light, &img_button_login_press, _LOGIN_onClick);   //��¼��ť���
	pButtonRegister = new Button(150, 470, 0, 0, &img_button_register_common, &img_button_register_light, &img_button_register_press, _REGISTER_onClick);   //ע�ᰴť���
	pButtonXueshenghui = new Button(180, 17, 0, 0, &img_button_xueshenghui_common, &img_button_xueshenghui_light, &img_button_xueshenghui_press, _XSH_onClick);//ѧ���������ť
	pButtonShelian = new Button(600, 17, 0, 0, &img_button_shelian_common, &img_button_shelian_light, &img_button_shelian_press, _SL_onClick);//����������ť
	pButtonGechuang= new Button(1000, 17, 0, 0, &img_button_gechuang_common, &img_button_gechuang_light, &img_button_gechuang_press, _GC_onClick);//�񴴻�����ť

	pListTable = new listTable(data["xueshenghui"][0]["agents"], 265, 180, 30, 60, 190, 320, 520);    //�б��

	/*  ע���ȼ�  */




	ExMessage msg;

	/*  ��ʼ����  */
	BeginBatchDraw();
	while (true)
	{
		while (peekmessage(&msg))
		{
			if (msg.y < 30 && msg.x < 1236 && msg.message == WM_LBUTTONDOWN) {
				SendMessage(hwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);   //����������ק
			}

			pButtonClose->OnEvent(msg);

			switch (UIinterface){
				/*     ��½����     */
			case LOGIN_UI:
				//ע���¼�
				pButtonLogin->OnEvent(msg);
				pButtonRegister->OnEvent(msg);
				pTextboxAccount->OnEvent(msg);
				pTextboxPassword->OnEvent(msg);
				//----------------------------------------------------------------
				//if (msg.x >= 340 && msg.x <= (340 + 40) && msg.y >= 275 &&
				//	msg.y <= 300 && msg.message == WM_LBUTTONDOWN) {
				//	//�Ƚ��û������˺��������Ƿ���ȷ
				//	if (pTextboxAccount->GetText() == USER_ACCOUNT && pTextboxPassword->GetText() == USER_PASSWORDS) {
				//		MessageBox(hwnd, L"����ɹ���", L"��ʾ", MB_OKCANCEL);
				//	}
				//	else {
				//		MessageBox(hwnd, L"�˺Ż��������", L"������ʾ", MB_OKCANCEL);
				//	}
				//}
				//ע��������¼� ���Ͼɣ�
				//pEdit3->ClickEvent(msg);
				//pEdit4->ClickEvent(msg);
				
				//��Ⱦ
				putimage(0, 0, &img_logo);

				pTextboxAccount->Show();
				pTextboxPassword->Show();
				pButtonLogin->Show();
				pButtonRegister->Show();

				settextstyle(30, 0, L"΢���ź�");
				settextcolor(RGB(14, 206, 234));
				outtextxy(140, 335, L"�˺ţ�");
				outtextxy(140, 405, L"���룺");
				//Edit edit();

				break;
				/*     ע�����     */
			case REGISTER_UI:
				putimage(0, 0, &img_logo);

				break;
				/*     �������     */
			case MANEGER_UI:
				//ע���¼�
				pButtonXueshenghui->OnEvent(msg);
				pButtonShelian->OnEvent(msg);
				pButtonGechuang->OnEvent(msg);
				//��Ⱦ
				putimage(0, 0, &img_bk_manager);
				
				pButtonXueshenghui->Show();
				pButtonShelian->Show();
				pButtonGechuang->Show();
				pListTable->Show();

				settextstyle(30, 0, L"΢���ź�");
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
	//���ó������ʾ��С��λ��
	MoveWindow(hwnd, 100, 100, 1280, 768, false);

	RECT windowsRC;
	GetWindowRect(hwnd, &windowsRC);

	int scrWidth, scrHeight;
	scrWidth = GetSystemMetrics(SM_CXSCREEN);
	scrHeight = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(hwnd, HWND_TOP, (scrWidth - windowsRC.right) / 2, (scrHeight - windowsRC.bottom) / 2, windowsRC.right - windowsRC.left, windowsRC.bottom - windowsRC.top, SWP_SHOWWINDOW);
	//ȥ���߿�
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~(WS_CAPTION | WS_SIZEBOX));
	//����Բ�ǻ�
	HRGN hRgn = CreateRoundRectRgn(0, 0, windowsRC.right - windowsRC.left, windowsRC.bottom - windowsRC.top, radius, radius);
	SetWindowRgn(hwnd, hRgn, true);
}