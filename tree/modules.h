#pragma once
#include "UIcontrol.h"

//注册控件
Textbox* pTextboxAccount;      //用户名编辑框
Textbox* pTextboxPassword;     //密码编辑框
Button* pButtonClose;       //关闭按钮（全局）
Button* pButtonLogin;       //登录按钮
Button* pButtonRegister;    //注册按钮

Button* pButtonXueshenghui;
Button* pButtonShelian;
Button* pButtonGechuang;
Button* pButtonAddAgent;
Button* pButtonDeleteAgent;
Button* pButtonChangeAgent;
Button* pButtonAddDepartment; 
Button* pButtonDeleteDepartment;
Button* pButtonChangeDepartment;

Button* pButtonAgentCancel;   //添加or修改成员界面 - 返回按钮
Button* pButtonAgentConfirm;  //添加or修改成员界面 - 确认按钮
Button* pButtonDepartmentCancel;   //添加or修改成员界面 - 返回按钮
Button* pButtonDepartmentConfirm;  //添加or修改部门界面 - 确认按钮

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

//注册界面
Textbox* pTextboxRegAccount;
Textbox* pTextboxRegPassword;
Textbox* pTextboxRegRePassword;
Textbox* pTextboxRegEmail;
Textbox* pTextboxRegCheckcode;
Button* pButtonRegGetCheckCode;
Button* pButtonRegConfirm;
Button* pButtonRegCancel;

//树形图界面
Button* pButtonToManager;