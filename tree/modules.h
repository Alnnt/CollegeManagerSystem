#pragma once
#include "UIcontrol.h"

//ע��ؼ�
Textbox* pTextboxAccount;      //�û����༭��
Textbox* pTextboxPassword;     //����༭��
Button* pButtonClose;       //�رհ�ť��ȫ�֣�
Button* pButtonLogin;       //��¼��ť
Button* pButtonRegister;    //ע�ᰴť

Button* pButtonXueshenghui;
Button* pButtonShelian;
Button* pButtonGechuang;
Button* pButtonAddAgent;
Button* pButtonDeleteAgent;
Button* pButtonChangeAgent;
Button* pButtonAddDepartment; 
Button* pButtonDeleteDepartment;
Button* pButtonChangeDepartment;

Button* pButtonAgentCancel;   //���or�޸ĳ�Ա���� - ���ذ�ť
Button* pButtonAgentConfirm;  //���or�޸ĳ�Ա���� - ȷ�ϰ�ť
Button* pButtonDepartmentCancel;   //���or�޸ĳ�Ա���� - ���ذ�ť
Button* pButtonDepartmentConfirm;  //���or�޸Ĳ��Ž��� - ȷ�ϰ�ť

Button* pButtonToTree;
Button* pButtonBackup;
Button* pButtonRetract;

listTable* pListTable;
listChosen* pListChosen;

Textbox* pTextboxAgentName;
Textbox* pTextboxAgentJob;
Textbox* pTextboxAgentUid;
Textbox* pTextboxAgentEmail;

Textbox* pTextboxDepartmentName;

//ע�����
Textbox* pTextboxRegAccount;
Textbox* pTextboxRegPassword;
Textbox* pTextboxRegRePassword;
Textbox* pTextboxRegEmail;
Textbox* pTextboxRegCheckcode;
Button* pButtonRegGetCheckCode;
Button* pButtonRegConfirm;
Button* pButtonRegCancel;

//����ͼ����
Button* pButtonToManager;