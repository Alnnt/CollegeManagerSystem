#pragma once
#include "includes.h"

//����ΪͳһЭ�����������м��
//cout << "Run " << endl;
enum TYPE_UI {
	LOGIN_UI,
	REGISTER_UI,
	MANEGER_UI
};

enum type_ins {
	IS_XueShengHui,  //ѧ����
	IS_SheLian,      //����
	IS_GeChuang      //��
};


void drawInstitutionChosen(IMAGE* chosen);