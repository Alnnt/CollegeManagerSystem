#include "includes.h"
#include "manager.h"

//index ѡ��������
type_ins institutionNow = IS_XueShengHui;   //��ǰѡ��Ļ���
int chosenDepartment = 0;   //��ǰѡ��Ĳ���
int chosenAgent = -1;       //��ǰѡ���ѧ��

int x_chosen_institution = 180;

void drawInstitutionChosen(IMAGE* chosen) {
	drawAlpha(x_chosen_institution,70,chosen);
}