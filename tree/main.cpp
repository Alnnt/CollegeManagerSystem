#include <easyx.h>
#include "resources.h"
#include "VisualEffects.h"
#include "manager.h"
#include "data.h"
#include "modules.h"
#include "functions.h"
#include "auth.h"


HWND hwnd;

extern LPCTSTR LOGIN_TIP;
extern LPCTSTR REGISTER_TIP;
extern Json::Value LIST_DATA;

extern     Permission    PERMISSION;
extern     string        PER_DEPARTMENT;
extern     int           CHOSEN_DEPARTMENT;
extern     int           CHOSEN_AGENT;

//���õ�ǰ����Ϊ��¼���棬���ڲ�ͬ�Ľ��棬ʵ��ѡ��й���
TYPE_UI UIinterface = LOGIN_UI;

using namespace std;
void DrawTree(int Y);

int main()
{
	/*  ����ͼ����Դ  */
	{
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

		loadimage(&img_bk_register, _T("./images\\bk_register.png"));
		loadimage(&img_button_RegGetCheckCode_common, _T("./images\\button_get_common.png"));
		loadimage(&img_button_RegGetCheckCode_light, _T("./images\\button_get_light.png"));
		loadimage(&img_button_RegGetCheckCode_press, _T("./images\\button_get_press.png"));



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

		loadimage(&img_button_add_common, _T("./images\\button_add_common.png"));
		loadimage(&img_button_add_light, _T("./images\\button_add_light.png"));
		loadimage(&img_button_add_press, _T("./images\\button_add_press.png"));
		loadimage(&img_button_delete_common, _T("./images\\button_delete_common.png"));
		loadimage(&img_button_delete_light, _T("./images\\button_delete_light.png"));
		loadimage(&img_button_delete_press, _T("./images\\button_delete_press.png"));
		loadimage(&img_button_change_common, _T("./images\\button_change_common.png"));
		loadimage(&img_button_change_light, _T("./images\\button_change_light.png"));
		loadimage(&img_button_change_press, _T("./images\\button_change_press.png"));


		loadimage(&img_chosen_insitution, _T("./images\\chosen_insitution.png"));
		loadimage(&img_listChosen_common, _T("./images\\listchosen_common.png"));
		loadimage(&img_listChosen_light, _T("./images\\listchosen_light.png"));
		loadimage(&img_listChosen_chosen, _T("./images\\listchosen_chosen.png"));
		loadimage(&img_listTable_light, _T("./images\\listtable_light.png"));
		loadimage(&img_listTable_chosen, _T("./images\\listtable_chosen.png"));
		
		loadimage(&img_bk_agent, _T("./images\\bk_agent.png"));
		loadimage(&img_bk_department, _T("./images\\bk_department.png"));
		loadimage(&img_button_cancel_common, _T("./images\\button_cancel_common.png"));
		loadimage(&img_button_cancel_light, _T("./images\\button_cancel_light.png"));
		loadimage(&img_button_cancel_press, _T("./images\\button_cancel_press.png"));
		loadimage(&img_button_confirm_common, _T("./images\\button_confirm_common.png"));
		loadimage(&img_button_confirm_light, _T("./images\\button_confirm_light.png"));
		loadimage(&img_button_confirm_press, _T("./images\\button_confirm_press.png"));
		
		loadimage(&img_bk_treelist, _T("./images\\bk_treelist.png"));
		loadimage(&img_button_totree_common, _T("./images\\button_totree_common.png"));
		loadimage(&img_button_totree_light, _T("./images\\button_totree_light.png"));
		loadimage(&img_button_totree_press, _T("./images\\button_totree_press.png"));
		loadimage(&img_button_tomanager_common, _T("./images\\button_tomanager_common.png"));
		loadimage(&img_button_tomanager_light, _T("./images\\button_tomanager_light.png"));
		loadimage(&img_button_tomanager_press, _T("./images\\button_tomanager_press.png"));
		loadimage(&img_button_backup_common, _T("./images\\button_backup_common.png"));
		loadimage(&img_button_backup_light, _T("./images\\button_backup_light.png"));
		loadimage(&img_button_backup_press, _T("./images\\button_backup_press.png"));
		loadimage(&img_button_retract_common, _T("./images\\button_retract_common.png"));
		loadimage(&img_button_retract_light, _T("./images\\button_retract_light.png"));
		loadimage(&img_button_retract_press, _T("./images\\button_retract_press.png"));
	}

	/*  ����������Դ  */
	//�û���Ϣ
	GeneratCheckCode();
	LOGIN_TIP = CharArrToLPCTSTR("");
	REGISTER_TIP = CharArrToLPCTSTR("");
	//json���ݿ�
	LoadJson();
	

	/*  ��ʼ�������ͼ�ռ�  */
	hwnd = initgraph(1280, 768); //EX_SHOWCONSOLE
	setbkcolor(RGB(238, 238, 238));
	cleardevice();
	settextcolor(BLACK);

	EnRoundWindows(hwnd, 25); //�����ޱ߿�Բ�ǻ�
	
	/*  ע��ؼ�  */
	//��½����
	{
	pTextboxAccount = new Textbox(200, 330, 320, 35, RGB(238, 238, 238), INPUT_COMMON);  //�˺ű༭��
	pTextboxPassword = new Textbox(200, 400, 320, 35, RGB(238, 238, 238), INPUT_PASSOWRD);  //����༭��
	pButtonClose = new Button(1236, 2, 0, 0, &img_button_close_common, &img_button_close_light, &img_button_close_press, close_onclick);   //�رհ�ť
	pButtonLogin = new Button(350, 470, 0, 0, &img_button_login_common, &img_button_login_light, &img_button_login_press, login_onclick);   //��¼��ť���
	pButtonRegister = new Button(150, 470, 0, 0, &img_button_register_common, &img_button_register_light, &img_button_register_press, register_onclick);   //ע�ᰴť���
	}
	//ע�����
	{
	pTextboxRegAccount =    new Textbox(230, 200, 330, 35, RGB(238, 238, 238), INPUT_COMMON);
	pTextboxRegPassword =   new Textbox(230, 270, 330, 35, RGB(238, 238, 238), INPUT_COMMON);
	pTextboxRegRePassword = new Textbox(230, 340, 330, 35, RGB(238, 238, 238), INPUT_COMMON);
	pTextboxRegEmail =      new Textbox(230, 410, 330, 35, RGB(238, 238, 238), INPUT_COMMON);
	pTextboxRegCheckcode =  new Textbox(230, 480, 230, 35, RGB(238, 238, 238), INPUT_COMMON);
	pButtonRegGetCheckCode = new Button(470, 480, 0, 0, &img_button_RegGetCheckCode_common, &img_button_RegGetCheckCode_light, &img_button_RegGetCheckCode_press, get_onclick);
	pButtonRegConfirm = new Button(370, 560, 0, 0, &img_button_confirm_common, &img_button_confirm_light, &img_button_confirm_press, reg_confirm_onclick);
	pButtonRegCancel =  new Button(160, 560, 0, 0, &img_button_cancel_common, &img_button_cancel_light, &img_button_cancel_press, reg_cancel_onclick);
	}
	//�������
	{
	pButtonXueshenghui = new Button(180, 17, 0, 0, &img_button_xueshenghui_common, &img_button_xueshenghui_light, &img_button_xueshenghui_press, xsh_onclick);//ѧ���������ť
	pButtonShelian = new Button(600, 17, 0, 0, &img_button_shelian_common, &img_button_shelian_light, &img_button_shelian_press, sl_onclick);//����������ť
	pButtonGechuang= new Button(1000, 17, 0, 0, &img_button_gechuang_common, &img_button_gechuang_light, &img_button_gechuang_press, gc_onclick);//�񴴻�����ť

	pButtonAddAgent = new Button(1120, 140, 0, 0, &img_button_add_common, &img_button_add_light, &img_button_add_press, add_agent_onclick); //��ӳ�Ա��ť
	pButtonDeleteAgent = new Button(1090, 140, 0, 0, &img_button_delete_common, &img_button_delete_light, &img_button_delete_press, delete_agent_onclick); //ɾ����Ա��ť
	pButtonChangeAgent = new Button(1060, 140, 0, 0, &img_button_change_common, &img_button_change_light, &img_button_change_press, change_agent_onclick); //�޸ĳ�Ա��ť
	pButtonAddDepartment = new Button(195, 140, 0, 0, &img_button_add_common, &img_button_add_light, &img_button_add_press, add_department_onclick); //��Ӳ��Ű�ť
	pButtonDeleteDepartment = new Button(165, 140, 0, 0, &img_button_delete_common, &img_button_delete_light, &img_button_delete_press, delete_department_onclick); //ɾ�����Ű�ť
	pButtonChangeDepartment = new Button(135, 140, 0, 0, &img_button_change_common, &img_button_change_light, &img_button_change_press, change_department_onclick); //��Ӳ��Ű�ť

	pListTable = new listTable(LIST_DATA[GetChosenInstitution()][0]["agents"], 240, 180, 30, 60, 190, 320, 520, &img_listTable_light, &img_listTable_chosen);    //��Ա�б��
	pListChosen = new listChosen(LIST_DATA[GetChosenInstitution()], 50, 170, 60, &img_listChosen_common, &img_listChosen_light, &img_listChosen_chosen);  //����ѡ���б��

	pButtonToTree = new Button(30, 30, 0, 0, &img_button_totree_common, &img_button_totree_light, &img_button_totree_press,to_tree_onclick); //������ͼ��ť
	pButtonBackup = new Button(80, 30, 0, 0, &img_button_backup_common, &img_button_backup_light, &img_button_backup_press, backup_onclick); //���ݴ浵��ť
	pButtonRetract = new Button(1240, 55, 0, 0, &img_button_retract_common, &img_button_retract_light, &img_button_retract_press, retract_onclick); //���ذ�ť
	}
	//���or�޸ĳ�Ա���Խ���
	{
	pButtonAgentCancel = new Button(460, 560, 0, 0, &img_button_cancel_common, &img_button_cancel_light, &img_button_cancel_press, agent_cancel_onclick);
	pButtonAgentConfirm = new Button(660, 560, 0, 0, &img_button_confirm_common, &img_button_confirm_light, &img_button_confirm_press, agent_confirm_onclick);
	pTextboxAgentName = new Textbox(520, 230, 320, 35, RGB(238, 238, 238), INPUT_COMMON);
	pTextboxAgentJob = new Textbox(520, 310, 320, 35, RGB(238, 238, 238), INPUT_COMMON);
	pTextboxAgentUid = new Textbox(520, 390, 320, 35, RGB(238, 238, 238), INPUT_COMMON);
	pTextboxAgentEmail = new Textbox(520, 470, 320, 35, RGB(238, 238, 238), INPUT_COMMON);
	}
	//���or�޸Ĳ������Խ���
	{
	pButtonDepartmentCancel = new Button(460, 460, 0, 0, &img_button_cancel_common, &img_button_cancel_light, &img_button_cancel_press, department_cancel_onclick);
	pButtonDepartmentConfirm = new Button(660, 460, 0, 0, &img_button_confirm_common, &img_button_confirm_light, &img_button_confirm_press, department_confirm_onclick);
	pTextboxDepartmentName = new Textbox(520, 340, 320, 35, RGB(238, 238, 238), INPUT_COMMON);
	}
	//����ͼ����
	{
	pButtonToManager = new Button(30, 30, 0, 0, &img_button_tomanager_common, &img_button_tomanager_light, &img_button_tomanager_press, to_manager_onclick);  //��������水ť
	TreeListInit(0, 30);
	}
	/*  ע���ȼ�  */




	ExMessage msg;

	/*  ��ʼ����  */
	BeginBatchDraw();

	//UIinterface = TREE_UI;  //***********��ʱ������****************************************************************************
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
				case LOGIN_UI:{
				//ע���¼�
				pButtonLogin->OnEvent(msg);
				pButtonRegister->OnEvent(msg);
				pTextboxAccount->OnEvent(msg);
				pTextboxPassword->OnEvent(msg);

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

				settextstyle(25, 0, L"΢���ź�");
				settextcolor(RGB(221, 0, 27));
				outtextxy(150, 440, LOGIN_TIP);
				break;
			}
					/*     ע�����     */
				case REGISTER_UI:{
				pTextboxRegAccount->OnEvent(msg);
				pTextboxRegPassword->OnEvent(msg);
				pTextboxRegRePassword->OnEvent(msg);
				pTextboxRegEmail->OnEvent(msg);
				pTextboxRegCheckcode->OnEvent(msg);
				pButtonRegConfirm->OnEvent(msg);
				pButtonRegCancel->OnEvent(msg);
				pButtonRegGetCheckCode->OnEvent(msg);

				putimage(0, 0, &img_bk_register);
				pTextboxRegAccount->Show();
				pTextboxRegPassword->Show();
				pTextboxRegRePassword->Show();
				pTextboxRegEmail->Show();
				pTextboxRegCheckcode->Show();
				pButtonRegConfirm->Show();
				pButtonRegCancel->Show();
				pButtonRegGetCheckCode->Show();

				settextstyle(30, 0, L"΢���ź�");
				settextcolor(RGB(7, 7, 152));
				outtextxy(125, 200, L"�˺ţ�");
				outtextxy(125, 270, L"���룺");
				outtextxy(125, 340, L"�ظ����룺");
				outtextxy(125, 410, L"���䣺");
				outtextxy(125, 480, L"��֤�룺");

				settextstyle(30, 0, L"΢���ź�");
				settextcolor(RGB(255, 169, 0));
				outtextxy(160, 615, REGISTER_TIP);
				break;
			}
					/*     �������     */
				case MANEGER_UI:{
				//ע���¼�
				pButtonXueshenghui->OnEvent(msg);
				pButtonShelian->OnEvent(msg);
				pButtonGechuang->OnEvent(msg);
				pListChosen->OnEvent(msg);
				pListTable->OnEvent(msg);

				pButtonToTree->OnEvent(msg);
				pButtonRetract->OnEvent(msg);

				//��Ⱦ
				putimage(0, 0, &img_bk_manager);
				
				pButtonXueshenghui->Show();
				pButtonShelian->Show();
				pButtonGechuang->Show();
				pListTable->Show();
				pListChosen->Show();
				pButtonToTree->Show();
				pButtonRetract->Show();

				if (PERMISSION == Admin) {
					pButtonAddDepartment->OnEvent(msg);
					pButtonDeleteDepartment->OnEvent(msg);
					pButtonChangeDepartment->OnEvent(msg);
					pButtonAddAgent->OnEvent(msg);
					pButtonDeleteAgent->OnEvent(msg);
					pButtonChangeAgent->OnEvent(msg);
					pButtonBackup->OnEvent(msg);
					
					pButtonAddDepartment->Show();
					pButtonDeleteDepartment->Show();
					pButtonChangeDepartment->Show();
					pButtonAddAgent->Show();
					pButtonDeleteAgent->Show();
					pButtonChangeAgent->Show();
					pButtonBackup->Show();
				}
				else if (PERMISSION == Minister && PER_DEPARTMENT == LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["name"].asString()) {
					pButtonAddAgent->OnEvent(msg);
					pButtonDeleteAgent->OnEvent(msg);
					pButtonChangeAgent->OnEvent(msg);
					pButtonChangeDepartment->OnEvent(msg);

					pButtonAddAgent->Show();
					pButtonDeleteAgent->Show();
					pButtonChangeAgent->Show();
					pButtonChangeDepartment->Show();
				}
				else if (PERMISSION == Common) {
					if (CHOSEN_AGENT != -1) {
						if (WStoS(pTextboxAccount->GetText()) == LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"][CHOSEN_AGENT]["name"].asString()) {
							pButtonChangeAgent->OnEvent(msg);

							pButtonChangeAgent->Show();
						}
					}
				}

				settextstyle(30, 0, L"΢���ź�");
				settextcolor(RGB(7, 7, 152));

				DrawInstitutionChosen(&img_chosen_insitution);  //����������ƶ�����
				break;
				}
				    /*   ��ӳ�Ա����   */
				case ADD_AGENT_UI:{
				pButtonAgentConfirm->OnEvent(msg);
				pButtonAgentCancel->OnEvent(msg);
				pTextboxAgentName->OnEvent(msg);
				pTextboxAgentJob->OnEvent(msg);
				pTextboxAgentUid->OnEvent(msg);
				pTextboxAgentEmail->OnEvent(msg);
				
				putimage(0, 0, &img_bk_agent);
				pButtonAgentConfirm->Show();
				pButtonAgentCancel->Show();
				pTextboxAgentName->Show();
				pTextboxAgentJob->Show();
				pTextboxAgentUid->Show();
				pTextboxAgentEmail->Show();

				settextstyle(30, 0, L"΢���ź�");
				settextcolor(RGB(7, 7, 152));
				outtextxy(450, 232, L"������");
				outtextxy(450, 312, L"ְλ��");
				outtextxy(450, 392, L"ѧ�ţ�");
				outtextxy(450, 472, L"���䣺");

				break;
			}
					/*   ��Ӳ��Ž���   */
				case ADD_DEPARTMENT_UI:{
					pButtonDepartmentConfirm->OnEvent(msg);
					pButtonDepartmentCancel->OnEvent(msg);
					pTextboxDepartmentName->OnEvent(msg);

					putimage(0, 0, &img_bk_department);
					pButtonDepartmentConfirm->Show();
					pButtonDepartmentCancel->Show();
					pTextboxDepartmentName->Show();

					settextstyle(30, 0, L"΢���ź�");
					settextcolor(RGB(7, 7, 152));
					outtextxy(450, 342, L"���ƣ�");
					break;
				}
					/*    ����ͼ����    */
				case TREE_UI: {
					//pTreeList->OnEvent(msg);
					TreeListOnEvent(msg);
					pButtonToManager->OnEvent(msg);

					//��Ⱦ
					putimage(0, 0, &img_bk_treelist);
					settextstyle(30, 0, L"΢���ź�");
					settextcolor(RGB(255, 255, 255));
					setlinecolor(RGB(255, 204, 63));
					HRGN hRgn = CreateRectRgn(0, 30, 1280, 738); //���Ժ����Ƶ�ȫ�ֱ���
					setcliprgn(hRgn);
					//DrawTree(30);

					pButtonToManager->Show();
					TreeListShow();
					setcliprgn(NULL);
					break;
				}
			}
			pButtonClose->Show();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	return 0;
}

