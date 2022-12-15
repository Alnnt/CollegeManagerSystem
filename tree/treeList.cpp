#include "treeList.h"

extern Json::Value LIST_DATA;

int TREE_X, TREE_Y;
int institutionX, departmentX, agentX;
int tailY;

void TreeListInit(int _x, int _y) {  //��ȡ����Ĭ������LIST_DATA
	TREE_X = _x;
	TREE_Y = _y;
	//posY = _y;
}

int TreeListNodeShow(string institution, int y ,const wchar_t* insName) {
	int posY = y;
	int headY; //tailY;
	headY = posY;
	for (int departmentIndex = 0; departmentIndex < LIST_DATA[institution].size(); ++departmentIndex) {  //����ÿ������
		int numAgents = LIST_DATA[institution][departmentIndex]["agents"].size();
		if (numAgents == 0) continue;
		if (departmentIndex == 0)headY = (numAgents - 1) * 30 / 2 + posY;
		else if (departmentIndex == LIST_DATA[institution].size() - 1)tailY = (numAgents - 1) * 30 / 2 + posY;
		line(departmentX - 150, (numAgents - 1) * 30 / 2 + posY + 13, departmentX - 10, (numAgents - 1) * 30 / 2 + posY + 13);  //������ߺ���
		line(departmentX + 80, (numAgents - 1) * 30 / 2 + posY + 13, departmentX + 250, (numAgents - 1) * 30 / 2 + posY + 13);  //�����ұߺ���

		outtextxy(departmentX, (numAgents - 1) * 30 / 2 + posY, CharArrToLPCTSTR(LIST_DATA[institution][departmentIndex]["name"].asCString()));
		for (int agentIndex = 0; agentIndex < numAgents; ++agentIndex) {   //���ڸò��ŵ�ÿ����Ա
			line(agentX - 150, posY + 13, agentX - 10, posY + 13);
			if (agentIndex != numAgents - 1) {
				line(agentX - 150, posY + 13, agentX - 150, posY + 17 + 25);
			}
			outtextxy(agentX, posY, CharArrToLPCTSTR(LIST_DATA[institution][departmentIndex]["agents"][agentIndex]["name"].asCString()));
			outtextxy(agentX + 100, posY, CharArrToLPCTSTR(LIST_DATA[institution][departmentIndex]["agents"][agentIndex]["uid"].asCString()));
			posY += 30;
		}
	}
	line(departmentX - 150, headY + 13, departmentX - 150, tailY + 13); //�����������
	line(institutionX + 70, (headY + tailY - 30) / 2 + 26, institutionX + 200, (headY + tailY - 30) / 2 + 26); //�����Ҳ����
	outtextxy(institutionX, (headY + tailY - 30) / 2 + 13, insName);
	return posY;
}

void TreeListShow() {
	int posY = TREE_Y;

	int headY, tailY;
	institutionX =  150;
	departmentX =  500;
	agentX =  900;
	posY = TreeListNodeShow("xueshenghui", posY, L"ѧ����");
	posY = TreeListNodeShow("shelian", posY, L"����");
	posY = TreeListNodeShow("gechuang", posY, L"��");
	{/*
	//ѧ����
	headY = posY;
	for (int departmentIndex = 0; departmentIndex < LIST_DATA["xueshenghui"].size(); ++departmentIndex) {  //����ÿ������
		int numAgents = LIST_DATA["xueshenghui"][departmentIndex]["agents"].size();
		if (numAgents == 0) continue;
		if (departmentIndex == 0)headY = (numAgents - 1) * 30 / 2 + posY;
		else if (departmentIndex == LIST_DATA["xueshenghui"].size() - 1)tailY = (numAgents - 1) * 30 / 2 + posY;
		line(departmentX - 150, (numAgents - 1) * 30 / 2 + posY + 13, departmentX - 10, (numAgents - 1) * 30 / 2 + posY + 13);  //������ߺ���
		line(departmentX + 80, (numAgents - 1) * 30 / 2 + posY + 13, departmentX + 250, (numAgents - 1) * 30 / 2 + posY + 13);  //�����ұߺ���

		outtextxy(departmentX, (numAgents - 1) * 30 / 2 + posY, CharArrToLPCTSTR(LIST_DATA["xueshenghui"][departmentIndex]["name"].asCString()));
		for (int agentIndex = 0; agentIndex < numAgents; ++agentIndex) {   //���ڸò��ŵ�ÿ����Ա
			line(agentX - 150, posY + 13, agentX - 10, posY + 13);
			if (agentIndex != numAgents - 1) {
				line(agentX - 150, posY + 13, agentX - 150, posY + 17 + 25);
			}
			outtextxy(agentX, posY, CharArrToLPCTSTR(LIST_DATA["xueshenghui"][departmentIndex]["agents"][agentIndex]["name"].asCString()));
			outtextxy(agentX + 100, posY, CharArrToLPCTSTR(LIST_DATA["xueshenghui"][departmentIndex]["agents"][agentIndex]["uid"].asCString()));
			posY += 30;
		}
	}
	line(departmentX - 150, headY + 13, departmentX - 150, tailY + 13); //�����������
	line(institutionX + 70, (headY + tailY - 30) / 2 + 26, institutionX + 200, (headY + tailY - 30) / 2 + 26); //�����Ҳ����
	outtextxy(institutionX, (headY + tailY - 30) / 2 + 13, L"ѧ����");

	//����
	headY = posY;
	for (int departmentIndex = 0; departmentIndex < LIST_DATA["shelian"].size(); ++departmentIndex) {  //����ÿ������
		int numAgents = LIST_DATA["shelian"][departmentIndex]["agents"].size();
		if (numAgents == 0) continue;
		if (departmentIndex == 0)headY = (numAgents - 1) * 30 / 2 + posY;
		else if (departmentIndex == LIST_DATA["shelian"].size() - 1)tailY = (numAgents - 1) * 30 / 2 + posY;
		line(departmentX - 150, (numAgents - 1) * 30 / 2 + posY + 13, departmentX - 10, (numAgents - 1) * 30 / 2 + posY + 13);  //������ߺ���
		line(departmentX + 80, (numAgents - 1) * 30 / 2 + posY + 13, departmentX + 250, (numAgents - 1) * 30 / 2 + posY + 13);  //�����ұߺ���

		outtextxy(departmentX, (numAgents - 1) * 30 / 2 + posY, CharArrToLPCTSTR(LIST_DATA["shelian"][departmentIndex]["name"].asCString()));
		for (int agentIndex = 0; agentIndex < numAgents; ++agentIndex) {   //���ڸò��ŵ�ÿ����Ա
			line(agentX - 150, posY + 13, agentX - 10, posY + 13);
			if (agentIndex != numAgents - 1) {
				line(agentX - 150, posY + 13, agentX - 150, posY + 17 + 25);
			}
			outtextxy(agentX, posY, CharArrToLPCTSTR(LIST_DATA["shelian"][departmentIndex]["agents"][agentIndex]["name"].asCString()));
			outtextxy(agentX + 100, posY, CharArrToLPCTSTR(LIST_DATA["shelian"][departmentIndex]["agents"][agentIndex]["uid"].asCString()));
			posY += 30;
		}
	}
	line(departmentX - 150, headY + 13, departmentX - 150, tailY + 13); //�����������
	line(institutionX + 70, (headY + tailY - 30) / 2 + 26, institutionX + 200, (headY + tailY - 30) / 2 + 26); //�����Ҳ����
	outtextxy(institutionX, (headY + tailY - 30) / 2 + 13, L"����");


	//��
	headY = posY;
	for (int departmentIndex = 0; departmentIndex < LIST_DATA["gechuang"].size(); ++departmentIndex) {  //����ÿ������
		int numAgents = LIST_DATA["gechuang"][departmentIndex]["agents"].size();
		if (numAgents == 0) continue;
		if (departmentIndex == 0)headY = (numAgents - 1) * 30 / 2 + posY;
		else if (departmentIndex == LIST_DATA["gechuang"].size() - 1)tailY = (numAgents - 1) * 30 / 2 + posY;
		line(departmentX - 150, (numAgents - 1) * 30 / 2 + posY + 13, departmentX - 10, (numAgents - 1) * 30 / 2 + posY + 13);  //������ߺ���
		line(departmentX + 80, (numAgents - 1) * 30 / 2 + posY + 13, departmentX + 250, (numAgents - 1) * 30 / 2 + posY + 13);  //�����ұߺ���

		outtextxy(departmentX, (numAgents - 1) * 30 / 2 + posY, CharArrToLPCTSTR(LIST_DATA["gechuang"][departmentIndex]["name"].asCString()));
		for (int agentIndex = 0; agentIndex < numAgents; ++agentIndex) {   //���ڸò��ŵ�ÿ����Ա
			line(agentX - 150, posY + 13, agentX - 10, posY + 13);
			if (agentIndex != numAgents - 1) {
				line(agentX - 150, posY + 13, agentX - 150, posY + 17 + 25);
			}
			outtextxy(agentX, posY, CharArrToLPCTSTR(LIST_DATA["gechuang"][departmentIndex]["agents"][agentIndex]["name"].asCString()));
			outtextxy(agentX + 100, posY, CharArrToLPCTSTR(LIST_DATA["gechuang"][departmentIndex]["agents"][agentIndex]["uid"].asCString()));
			posY += 30;
		}
	}
	line(departmentX - 150, headY + 13, departmentX - 150, tailY + 13); //�����������
	line(institutionX + 70, (headY + tailY - 30) / 2 + 26, institutionX + 200, (headY + tailY - 30) / 2 + 26); //�����Ҳ����
	outtextxy(institutionX, (headY + tailY - 30) / 2 + 13, L"��");
	*/} //ע�Ͷ�
}




void TreeListOnEvent(ExMessage& msg){
	if (msg.message == WM_MOUSEWHEEL) {
		if (msg.wheel > 0) {
			TREE_Y += 40;
		}
		else {
			TREE_Y -= 40;
		}
	}
	if (TREE_Y > 30)TREE_Y = 30;
}

void TreeListToTop(void) {
	TREE_Y = 30;
}