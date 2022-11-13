#pragma once
#include "includes.h"

//本库为统一协调管理所用中间件
//cout << "Run " << endl;
enum TYPE_UI {
	LOGIN_UI,
	REGISTER_UI,
	MANEGER_UI
};

enum type_ins {
	IS_XueShengHui,  //学生会
	IS_SheLian,      //社联
	IS_GeChuang      //格创
};


void drawInstitutionChosen(IMAGE* chosen);