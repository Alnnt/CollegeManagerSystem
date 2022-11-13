#include "includes.h"
#include "manager.h"

//index 选择项索引
type_ins institutionNow = IS_XueShengHui;   //当前选择的机构
int chosenDepartment = 0;   //当前选择的部门
int chosenAgent = -1;       //当前选择的学生

int x_chosen_institution = 180;

void drawInstitutionChosen(IMAGE* chosen) {
	drawAlpha(x_chosen_institution,70,chosen);
}