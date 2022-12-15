#pragma once
#include "common.h"
#include "data.h"
#include "VisualEffects.h"

class listChosen
{
public:
	listChosen(Json::Value data, int x, int y, int lineDistance, IMAGE* img_listChosen_common, IMAGE* img_listChosen_light, IMAGE* img_listChosen_chosen);
	void Show();
	void resetData(Json::Value data);
	void OnEvent(ExMessage& msg);
	void toTop(void);
private:
	int x;
	int y;
	int width;
	int IMGheight;
	int lineDistance;
	int indexLighter;  //对于indexLighter索引渲染点燃图片UI
	Json::Value data;
	int numAgents;
	IMAGE* img_listChosen_common;
	IMAGE* img_listChosen_light;
	IMAGE* img_listChosen_chosen;
	int headIndex;
	int maxShowLine;
};