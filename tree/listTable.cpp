#include "listTable.h"
#include "functions.h"
#include "log.h"
#include "VisualEffects.h"

extern int CHOSEN_AGENT;

listTable::listTable(Json::Value data, int x, int y, int lineDistance, int nameDistance, int jobDistance, int idDistance, int emailDistance, IMAGE* img_listTable_light, IMAGE* img_listTable_chosen){
	this->data = data;
	this->numAgents = data.size();
	this->x = x;
	this->y = y;
	this->width = img_listTable_light->getwidth();
	this->lineDistance = lineDistance;
	this->nameDistance = nameDistance;
	this->jobDistance = jobDistance;
	this->idDistance = idDistance;
	this->emailDistance = emailDistance;
	this->indexLighter = -1;
	this->img_listTable_light = img_listTable_light;
	this->img_listTable_chosen = img_listTable_chosen;
	this->TEXTdeviation = 30;
	this->headIndex = 0;
	this->maxShowLine = 17;
}
//int isInLine = 0;
//if (msg.x > x && msg.x < x + width) {
//	for (int index = 0; index < numAgents; ++index) {
//		if (y + index * lineDistance < msg.y && msg.y < y + (index + 1) * lineDistance - (lineDistance - IMGheight)) {
//			indexLighter = index;
//			isInLine = 1;
//			if (msg.message == WM_LBUTTONUP) { //���ؼ���׼ȷ����
//				chosenDepartment = index;
//				//��Ϊֻ��һ��listChosen��������Դ˴�͵���ˣ�ֱ������ִ�д˺���
//				_ListChosen_onClick(index);
//			}
//			break;
//		}
//	}
//	if (!isInLine) {
//		indexLighter = -1;
//	}
//}
//else {
//	indexLighter = -1;
//}
void listTable::Show() {
	int thisLineY = y;
	for (int index = headIndex; index < numAgents && index - headIndex < maxShowLine; ++index) {
		if (index == CHOSEN_AGENT) {
			DrawAlpha(x, thisLineY, img_listTable_chosen);
		}
		else if (index == indexLighter) {
			DrawAlpha(x, thisLineY, img_listTable_light);
		}
		//���ڳ���10���������⣬������***********   //��ʹ�ù��������
		char* idTmp = IntToCstr(index + 1);
		LPCTSTR id = CharArrToLPCTSTR(idTmp);
		LPCTSTR name = CharArrToLPCTSTR(data[index]["name"].asString().c_str());
		LPCTSTR job = CharArrToLPCTSTR(data[index]["job"].asString().c_str());
		LPCTSTR uid = CharArrToLPCTSTR(data[index]["uid"].asString().c_str());
		LPCTSTR email = CharArrToLPCTSTR(data[index]["email"].asString().c_str());
		outtextxy(TEXTdeviation + x, thisLineY, id);
		outtextxy(TEXTdeviation + x + nameDistance, thisLineY,name);
		outtextxy(TEXTdeviation + x + jobDistance, thisLineY, job);
		outtextxy(TEXTdeviation + x + idDistance, thisLineY, uid);
		outtextxy(TEXTdeviation + x + emailDistance, thisLineY, email);

		free(idTmp);
		delete id;
		delete name;
		delete job;
		delete uid;
		delete email;
		thisLineY += lineDistance;
	}
}

void listTable::OnEvent(ExMessage& msg) {
	int isInLine = 0;
	if (msg.x > x && msg.x < x + width) {
		for (int index = headIndex; index < numAgents && index - headIndex < maxShowLine; ++index) {
			if (y + (index-headIndex) * lineDistance < msg.y && msg.y < y + (index-headIndex + 1) * lineDistance) {
				indexLighter = index;
				isInLine = 1;
				if (msg.message == WM_LBUTTONUP) { //�������б�׼ȷ����
					//��Ϊֻ��һ��listTable��������Դ˴�͵���ˣ�ֱ������ִ�д˺���
					PlayClickSound();
					list_table_onclick(index);
				}
				break;
			}
		}
		if (!isInLine) {
			indexLighter = -1;
		}
		//�������¼�
		if (msg.message == WM_MOUSEWHEEL && numAgents > maxShowLine) {
			if (msg.y > y && msg.y < y + lineDistance * maxShowLine) {  //�и� 30 *  ���� 17 = 510
				if (msg.wheel > 0) { //���Ϲ���
					if (headIndex >= 2) {
						headIndex -= 2;
					}
					else {
						headIndex = 0;
					}
				}
				else {               //���¹���
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


void listTable::resetData(Json::Value newData) {
	data = newData;
	numAgents = data.size();
}

void listTable::toTop(void) {
	headIndex = 0;
}