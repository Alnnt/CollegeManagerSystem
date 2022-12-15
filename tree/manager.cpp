//#include "includes.h"
#include "manager.h"
#include "UIcontrol.h"

//index ѡ��������
type_ins CHOSEN_INSTITUTION = IS_XueShengHui;   //��ǰѡ��Ļ���
int CHOSEN_DEPARTMENT = 0;   //��ǰѡ��Ĳ���
int CHOSEN_AGENT = -1;       //��ǰѡ���ѧ��

int LIST_CHOSEN_ROLL = 0;     //�����б����λ��
int LIST_TABLE_ROLL = 0;      //��Ա�б����λ��

int X_CHOSEN_INSTITUTION = 180;//����ѡ����XĬ������(��ʼ������ʱ)
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