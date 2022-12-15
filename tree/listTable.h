#pragma once
#include "common.h"
#include "data.h"

class listTable 
{
public:
	listTable(Json::Value data,int x,int y,int lineDistance,int nameDistance,int jobDistance,int idDistance,int emailDistance,IMAGE* img_listTable_light,IMAGE* img_listTable_chosen);
	void Show();
	void OnEvent(ExMessage& msg);
	void resetData(Json::Value data);
	void toTop(void);
private:
	int x;
	int y;
	int width;
	int lineDistance;
	int nameDistance;
	int jobDistance;
	int idDistance;
	int emailDistance;
	int indexLighter;
	Json::Value data;
	int numAgents;
	IMAGE* img_listTable_light;
	IMAGE* img_listTable_chosen;
	int TEXTdeviation;  //��������б�������ƫ��
	int headIndex;      //�б�����ʵ������λ�ã�ʵ�������ֹ���
	int maxShowLine;    //��ʾ���������
};