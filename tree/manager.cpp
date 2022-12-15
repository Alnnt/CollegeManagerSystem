//#include "includes.h"
#include "manager.h"
#include "UIcontrol.h"

//index 选择项索引
type_ins CHOSEN_INSTITUTION = IS_XueShengHui;   //当前选择的机构
int CHOSEN_DEPARTMENT = 0;   //当前选择的部门
int CHOSEN_AGENT = -1;       //当前选择的学生

int LIST_CHOSEN_ROLL = 0;     //部门列表滚动位置
int LIST_TABLE_ROLL = 0;      //成员列表滚动位置

int X_CHOSEN_INSTITUTION = 180;//机构选择条X默认坐标(初始化窗口时)
int dscX = 180;

edit_type EDIT_TYPE = EDIT_ADD;

string GetChosenInstitution() {
	switch (CHOSEN_INSTITUTION) {
	case IS_XueShengHui:
		return "xueshenghui";
	case IS_SheLian:
		return "shelian";
	case IS_GeChuang:
		return "gechuang";
	}
}

void DrawInstitutionChosen(IMAGE* chosen) {
	DrawAlpha(X_CHOSEN_INSTITUTION,70,chosen);
}