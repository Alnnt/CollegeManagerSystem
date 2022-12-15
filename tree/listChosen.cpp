#include "listChosen.h"
#include "manager.h"
#include "functions.h"
#include "VisualEffects.h"

//----------record Log----------
//#include <iostream>
//using namespace std;
//------------------------------
extern int CHOSEN_DEPARTMENT;

listChosen::listChosen(Json::Value data, int x, int y, int lineDistance, IMAGE* img_listChosen_common, IMAGE* img_listChosen_light, IMAGE* img_listChosen_chosen) {
	this->data = data;
	this->numAgents = data.size();
	this->x = x;
	this->y = y;
	this->width = img_listChosen_common->getwidth();
	this->IMGheight = img_listChosen_common->getheight();
	this->lineDistance = lineDistance;
	this->indexLighter = -1;
	this->img_listChosen_common = img_listChosen_common;
	this->img_listChosen_light = img_listChosen_light;
	this->img_listChosen_chosen = img_listChosen_chosen;
	this->headIndex = 0;
	this->maxShowLine = 9;
}

void listChosen::Show() {
	int thisLineY = y;
	for (int index = headIndex; index < numAgents && index - headIndex < maxShowLine; ++index) {
			if (index == indexLighter) {
				DrawAlpha(x, thisLineY, img_listChosen_light);
			}
			else
			{
				DrawAlpha(x, thisLineY, img_listChosen_common);
			}
			if (index == CHOSEN_DEPARTMENT) {
				DrawAlpha(x, thisLineY, img_listChosen_chosen);
			}
		LPCTSTR name = CharArrToLPCTSTR(data[index]["name"].asString().c_str());
		outtextxy(x + 30, thisLineY + 12, name);  //这里调整文字的偏移

		delete name;
		thisLineY += lineDistance;
	}
}

void listChosen::OnEvent(ExMessage& msg) {
	int isInButton = 0;
	if (msg.x > x && msg.x < x + width) {
		for (int index = headIndex; index < numAgents && index - headIndex < maxShowLine; ++index) {
			if (y + (index-headIndex) * lineDistance < msg.y && msg.y < y + (index-headIndex + 1) * lineDistance - (lineDistance - IMGheight)) {
				indexLighter = index;
				isInButton = 1;
				if (msg.message == WM_LBUTTONUP) { //当控件被准确单击
					CHOSEN_DEPARTMENT = index;
					//因为只有一个listChosen组件，所以此处偷懒了，直接锁定执行此函数
					PlayClickSound();
					list_chosen_onclick(index);
				}
				break;
			}
		}
		if (!isInButton) {
			indexLighter = -1;
		}
		//鼠标滚轮事件
		if (msg.message == WM_MOUSEWHEEL && numAgents > maxShowLine) {
			if (msg.y > y && msg.y < y + lineDistance * maxShowLine) {  //行高 30 *  列数 9 = 510
				if (msg.wheel > 0) { //向上滚动
					if (headIndex >= 2) {
						headIndex -= 2;
					}
					else {
						headIndex = 0;
					}
				}
				else {               //向下滚动
					if (headIndex < numAgents - maxShowLine) {
						headIndex += 2;
					}
				}
			}
		}
	}
	else {
		indexLighter = -1;
	}

}

void listChosen::resetData(Json::Value newData) {
	data = newData;
	numAgents = data.size();
}

void listChosen::toTop(void) {
	headIndex = 0;
}