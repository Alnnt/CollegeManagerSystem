#pragma once
#include "common.h"
//#include "includes.h"
#include "common.h"
#include "data.h"
class listTable 
{
public:
	listTable(Json::Value data,int x,int y,int lineDistance,int nameDistance,int jobDistance,int idDistance,int emailDistance);
	void Show();
	void resetData(Json::Value data);
private:
	int x;
	int y;
	int lineDistance;
	int nameDistance;
	int jobDistance;
	int idDistance;
	int emailDistance;
	Json::Value data;
	int numAgents;

};