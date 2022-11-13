#include "listTable.h"



std::wstring GetWStringByChar(const char* szString)
{
	std::wstring wstrString;
	if (szString != NULL)
	{
		std::string str(szString);
		wstrString.assign(str.begin(), str.end());
	}

	return wstrString;
}

listTable::listTable(Json::Value data, int x, int y, int lineDistance, int nameDistance, int jobDistance, int idDistance, int emailDistance){
	this->data = data;
	this->numAgents = data.size();
	this->x = x;
	this->y = y;
	this->lineDistance = lineDistance;
	this->nameDistance = nameDistance;
	this->jobDistance = jobDistance;
	this->idDistance = idDistance;
	this->emailDistance = emailDistance;
}

void listTable::Show() {
	int thisLineY = y;
	for (int i = 0; i < numAgents; ++i) {
		char idTmp[2] = { i + '1' , '\0' };
		LPCTSTR id = charArrToLPCTSTR(idTmp);
		LPCTSTR name = charArrToLPCTSTR(data[i]["name"].asString().c_str());
		LPCTSTR job = charArrToLPCTSTR(data[i]["job"].asString().c_str());
		LPCTSTR uid = charArrToLPCTSTR(data[i]["uid"].asString().c_str());
		LPCTSTR email = charArrToLPCTSTR(data[i]["email"].asString().c_str());
		outtextxy(x, thisLineY, id);
		outtextxy(x + nameDistance, thisLineY,name);
		outtextxy(x + jobDistance, thisLineY, job);
		outtextxy(x + idDistance, thisLineY, uid);
		outtextxy(x + emailDistance, thisLineY, email);

		delete name;
		delete job;
		delete uid;
		delete email;
		thisLineY += lineDistance;
	}
}

void resetData(Json::Value newData) {
	//data = newData;
}
