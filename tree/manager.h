#pragma once
#include <easyx.h>
#include <string>
//#include "includes.h"                //ʺɽ�м��������ɾ������

//����ΪͳһЭ�����������м��
//cout << "Run " << endl;
enum TYPE_UI {
	LOGIN_UI,            //��½����
	REGISTER_UI,         //ע����� *** �Ѹ�
	MANEGER_UI,          //�������
	ADD_AGENT_UI,        //���or�޸���Ա����
	ADD_DEPARTMENT_UI,   //���or�޸Ĳ��Ž���
	TREE_UI              //����ͼUI
};

enum type_ins {
	IS_XueShengHui,  //ѧ����
	IS_SheLian,      //����
	IS_GeChuang      //��
};

enum edit_type {
	EDIT_ADD,
	EDIT_CHANGE
};

std::string GetChosenInstitution();
void DrawInstitutionChosen(IMAGE* chosen);