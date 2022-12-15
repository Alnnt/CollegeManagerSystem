#pragma once
#include <easyx.h>
#include <string>
//#include "includes.h"                //屎山中间件，不能删！！！

//本库为统一协调管理所用中间件
//cout << "Run " << endl;
enum TYPE_UI {
	LOGIN_UI,            //登陆界面
	REGISTER_UI,         //注册界面 *** 已噶
	MANEGER_UI,          //管理界面
	ADD_AGENT_UI,        //添加or修改人员界面
	ADD_DEPARTMENT_UI,   //添加or修改部门界面
	TREE_UI              //树形图UI
};

enum type_ins {
	IS_XueShengHui,  //学生会
	IS_SheLian,      //社联
	IS_GeChuang      //格创
};

enum edit_type {
	EDIT_ADD,
	EDIT_CHANGE
};

std::string GetChosenInstitution();
void DrawInstitutionChosen(IMAGE* chosen);