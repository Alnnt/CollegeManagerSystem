#include "includes.h"
#include "textbox.h"

HWND hwnd;

//���ڲ�ͬ�Ľ��棬ʵ��ѡ��й���
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




	const wstring USER_ACCOUNT = L"admin";			//�û���¼�˺�
	const wstring USER_PASSWORDS = L"123456";			//�û���¼����

	hwnd = initgraph(800, 550);
	setbkcolor(RGB(238, 238, 238));
	cleardevice();
	settextcolor(BLACK);


	settextstyle(20, 0, L"΢���ź�");

	Edit* pTextboxAccount = new Edit(120, 238, 200, 25, RGB(238, 238, 238));  //�˺ű༭��
	Edit* pTextboxPassword = new Edit(120, 278, 200, 25, RGB(238, 238, 238));  //����༭��
	Edit* pEdit3 = new Edit(340, 275, 40, 25, RGB(238, 238, 238));   //��¼��ť���
	Edit* pEdit4 = new Edit(220, 275, 40, 25, RGB(238, 238, 238));   //�˳���ť���
	

	ExMessage msg;    //�����Ϣ
	//Edit edit();

	BeginBatchDraw();
	while (true)
	{
		
		while (peekmessage(&msg))
		{
			switch (UIinterface){
				/*     ��½����     */
			case LOGIN_UI:
				//ע��༭���¼���������
				pTextboxAccount->OnEvent(msg);
				pTextboxPassword->OnEvent(msg);

				if (msg.x >= 340 && msg.x <= (340 + 40) && msg.y >= 275 &&
					msg.y <= 300 && msg.message == WM_LBUTTONDOWN) {
					//�Ƚ��û������˺��������Ƿ���ȷ
					if (pTextboxAccount->GetText() == USER_ACCOUNT && pTextboxPassword->GetText() == USER_PASSWORDS) {
						MessageBox(hwnd, L"����ɹ���", L"��ʾ", MB_OKCANCEL);
					}
					else {
						MessageBox(hwnd, L"�˺Ż��������", L"������ʾ", MB_OKCANCEL);
					}
				}
				//ע��������¼�
				pEdit3->ClickEvent(msg);
				pEdit4->ClickEvent(msg);

				break;
				/*     ע�����     */
			case REGISTER_UI:

				break;
			}
		}

		//��Ⱦ
		putimage(0, 0, &img_logo);

		pTextboxAccount->Show();
		pTextboxPassword->Show();
		pEdit3->Show();
		pEdit4->Show();

		outtextxy(70, 240, L"�˺ţ�");
		outtextxy(70, 280, L"���룺");
		outtextxy(340, 277, L"��¼");
		outtextxy(220, 277, L"�˳�");
		//Edit edit();


		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	return 0;
}
