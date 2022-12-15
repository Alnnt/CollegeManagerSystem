#include "functions.h"
#include "manager.h"
#include "auth.h"
#include "data.h"
#include "VisualEffects.h"


extern     Textbox*      pTextboxAccount;
extern     Textbox*      pTextboxPassword;
extern     Button*       pButtonClose;
extern     Button*       pButtonLogin;
extern     Button*       pButtonRegiste;
	       			   
extern     Textbox*      pTextboxRegAccount;
extern     Textbox*      pTextboxRegPassword;
extern     Textbox*      pTextboxRegRePassword;
extern     Textbox*      pTextboxRegEmail;
extern     Textbox*      pTextboxRegCheckcode;


extern     Textbox*      pTextboxAgentName;
extern     Textbox*      pTextboxAgentJob;
extern     Textbox*      pTextboxAgentUid;
extern     Textbox*      pTextboxAgentEmail;
extern     Textbox*      pTextboxDepartmentName;
	       			   
extern     listTable*    pListTable;
extern     listChosen*   pListChosen;
	       			   
extern     HWND          hwnd;
extern     TYPE_UI       UIinterface;
extern     type_ins      CHOSEN_INSTITUTION;
		  			   
extern     Json::Value   LIST_DATA;
extern     int           X_CHOSEN_INSTITUTION;
extern     int           CHOSEN_DEPARTMENT;
extern     int           CHOSEN_AGENT;

extern     edit_type     EDIT_TYPE;

extern     LPCTSTR       LOGIN_TIP;
extern     LPCTSTR       REGISTER_TIP;

extern     Permission    PERMISSION;
extern     string        PER_DEPARTMENT;

Json::Value BACK_STACK;

void close_onclick(void) {
	//retract_onclick();
	SaveJson();
	exit(0);
}

void login_onclick(void) {
	delete(LOGIN_TIP);
	string re = Login(pTextboxAccount->GetText(), pTextboxPassword->GetText());
	LOGIN_TIP = CharArrToLPCTSTR(re.c_str());

	char* token = (char*)malloc((re.size() + 1) * sizeof(char));
	strcpy(token, re.c_str());

	string left = strtok(token, "|");
	//cout << left << endl;

	if (left == "Admin") {
		PERMISSION = Admin;
		UIinterface = MANEGER_UI;
	}
	else if (left == "Minister") {
		string right = strtok(NULL, "|");
		PERMISSION = Minister;
		PER_DEPARTMENT = right;
		UIinterface = MANEGER_UI;
		//cout << PER_DEPARTMENT;
	}
	if (left == "Common") {
		//MessageBox(hwnd, L"登入成功！", L"提示", MB_OKCANCEL);
		PERMISSION = Common;
		UIinterface = MANEGER_UI;
	}
}

void register_onclick(void) {
	UIinterface = REGISTER_UI;
}

void xsh_onclick(void) {
	CHOSEN_INSTITUTION = IS_XueShengHui;
	CHOSEN_DEPARTMENT = 0;
	CHOSEN_AGENT = -1;
	pListChosen->resetData(LIST_DATA[GetChosenInstitution()]);
	if (LIST_DATA[GetChosenInstitution()].size() != 0) {
		pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]); //当为空时候改命令会自动创建agents对象 - BUG
	}
	X_CHOSEN_INSTITUTION = 180;
	pListChosen->toTop();
	pListTable->toTop();
}

void sl_onclick(void) {
	CHOSEN_INSTITUTION = IS_SheLian;
	CHOSEN_DEPARTMENT = 0;
	CHOSEN_AGENT = -1;
	//cout << listData[GetChosenInstitution()].toStyledString() << endl;
	pListChosen->resetData(LIST_DATA[GetChosenInstitution()]);
	if (LIST_DATA[GetChosenInstitution()].size() != 0) {
		pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]);
	}

	//FlushMove(600);
	//deX = 600;
	//std::thread t1(FlushMove);
	X_CHOSEN_INSTITUTION = 600;
	pListChosen->toTop();
	pListTable->toTop();
}

void gc_onclick(void) {
	CHOSEN_INSTITUTION = IS_GeChuang;
	CHOSEN_DEPARTMENT = 0;
	CHOSEN_AGENT = -1;
	pListChosen->resetData(LIST_DATA[GetChosenInstitution()]);
	if (LIST_DATA[GetChosenInstitution()].size() != 0) {
		pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]);
	}
	X_CHOSEN_INSTITUTION = 1000;
	pListChosen->toTop();
	pListTable->toTop();
}

void list_chosen_onclick(int index) {
	CHOSEN_DEPARTMENT = index;
	CHOSEN_AGENT = -1;
	pListTable->toTop();
	pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]);
}

void list_table_onclick(int index) {
	CHOSEN_AGENT = index;

}

void add_agent_onclick() {
	if (CHOSEN_DEPARTMENT == -1) {
		return;
	}
	EDIT_TYPE = EDIT_ADD;
	UIinterface = ADD_AGENT_UI;
}

void delete_agent_onclick() {
	if (CHOSEN_DEPARTMENT == -1 || CHOSEN_AGENT == -1) {
		return;
	}

	Json::Value tmp = NULL; //保存被删除的信息，后续用于实现撤回功能
	LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"].removeIndex(CHOSEN_AGENT,&tmp);
	//cout << tmp.toStyledString() << endl;
	CHOSEN_AGENT -= 1;
	pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]);

	//兼容撤回功能
	Json::Value record;
	record["token"] = "DeleteAgent";
	record["posInstitution"] = GetChosenInstitution();
	record["posDepartment"] = CHOSEN_DEPARTMENT;
	record["posAgent"] = CHOSEN_AGENT;
	record["data"] = tmp;
	BACK_STACK.append(record);
	//cout << BACK_STACK.toStyledString() << endl;

}

void change_agent_onclick() {
	if (CHOSEN_DEPARTMENT == -1 ||  CHOSEN_AGENT == -1 || LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"].size() == 0) {
		return;
	}
	LPCTSTR tmpName = CharArrToLPCTSTR(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"][CHOSEN_AGENT]["name"].asCString());
	LPCTSTR tmpJob = CharArrToLPCTSTR(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"][CHOSEN_AGENT]["job"].asCString());
	LPCTSTR tmpUid = CharArrToLPCTSTR(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"][CHOSEN_AGENT]["uid"].asCString());
	LPCTSTR tmpEmail = CharArrToLPCTSTR(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"][CHOSEN_AGENT]["email"].asCString());

	pTextboxAgentName->SetText(tmpName);
	pTextboxAgentJob->SetText(tmpJob);
	pTextboxAgentUid->SetText(tmpUid);
	pTextboxAgentEmail->SetText(tmpEmail);
	
	EDIT_TYPE = EDIT_CHANGE;
	UIinterface = ADD_AGENT_UI;
	delete tmpName;
	delete tmpJob;
	delete tmpUid;
	delete tmpEmail;
}

void add_department_onclick() {
	EDIT_TYPE = EDIT_ADD;
	UIinterface = ADD_DEPARTMENT_UI;

}

void delete_department_onclick() {
	//cout << "chosenDepartment = " << chosenDepartment << endl;
	Json::Value tmp = NULL; //保存被删除的信息，后续用于实现撤回功能
	if (CHOSEN_DEPARTMENT != -1) {
		LIST_DATA[GetChosenInstitution()].removeIndex(CHOSEN_DEPARTMENT, &tmp);
		//cout << tmp.toStyledString() << endl;
		//兼容撤回功能
		Json::Value record;
		record["token"] = "DeleteDepartment";
		record["posInstitution"] = GetChosenInstitution();
		record["posDepartment"] = CHOSEN_DEPARTMENT;
		record["data"] = tmp;
		BACK_STACK.append(record);//兼容撤回功能

		if (CHOSEN_DEPARTMENT != 0) {
			CHOSEN_DEPARTMENT -= 1;
		}
		pListChosen->resetData(LIST_DATA[GetChosenInstitution()]);
	}

}

void change_department_onclick() {
	cout << LIST_DATA[GetChosenInstitution()].size() << endl;
	if (CHOSEN_DEPARTMENT != -1 && LIST_DATA[GetChosenInstitution()].size() != 0) {
		LPCTSTR tmpName = CharArrToLPCTSTR(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["name"].asCString());
		pTextboxDepartmentName->SetText(tmpName);

		EDIT_TYPE = EDIT_CHANGE;
		UIinterface = ADD_DEPARTMENT_UI;

		delete tmpName;
	}
}

void agent_cancel_onclick() {
	UIinterface = MANEGER_UI;
	pTextboxAgentName->ClearText();
	pTextboxAgentJob->ClearText();
	pTextboxAgentUid->ClearText();
	pTextboxAgentEmail->ClearText();
}

void agent_confirm_onclick() {
	Json::Value agent;
	char* tmpName = LpctstrToCharArr(pTextboxAgentName->GetText().c_str());
	char* tmpJob = LpctstrToCharArr(pTextboxAgentJob->GetText().c_str());
	char* tmpUid = LpctstrToCharArr(pTextboxAgentUid->GetText().c_str());
	char* tmpEmail = LpctstrToCharArr(pTextboxAgentEmail->GetText().c_str());
	agent["name"] = tmpName;
	agent["job"] = tmpJob;
	agent["uid"] = tmpUid;
	agent["email"] = tmpEmail;
	//兼容撤回功能
	Json::Value record;
	record["token"] = "AddAgent";
	record["posInstitution"] = GetChosenInstitution();
	record["posDepartment"] = CHOSEN_DEPARTMENT;

	switch (EDIT_TYPE)
	{
	case EDIT_ADD:   //case互换
		if (CHOSEN_AGENT == -1) {
			LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"].append(agent);
			record["posAgent"] = LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"].size() - 1;//兼容撤回功能

		}
		else {
			LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"].insert(CHOSEN_AGENT + 1, agent);
			record["posAgent"] = CHOSEN_AGENT + 1;//兼容撤回功能

		}
		pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]);
		break;
	case EDIT_CHANGE:
		record["token"] = "ChangeAgent";//兼容撤回功能
		record["posAgent"] = CHOSEN_AGENT;
		record["data"] = LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"][CHOSEN_AGENT];

		LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"][CHOSEN_AGENT] = agent;
		pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]);
	}
	free(tmpName);
	free(tmpJob);
	free(tmpUid);
	free(tmpEmail);
	agent_cancel_onclick();

	BACK_STACK.append(record);//兼容撤回功能
}

void department_cancel_onclick() {
	UIinterface = MANEGER_UI;
	pTextboxDepartmentName->ClearText();
}

void department_confirm_onclick() {
	Json::Value agent;
	char* tmpName = LpctstrToCharArr(pTextboxDepartmentName->GetText().c_str());
	agent["name"] = tmpName;

	//兼容撤回功能
	Json::Value record;
	record["token"] = "AddDepartment";
	record["posInstitution"] = GetChosenInstitution();
	record["data"] = LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["name"];
	switch (EDIT_TYPE)
	{
	case EDIT_ADD:
		if (CHOSEN_DEPARTMENT < 1) {
			LIST_DATA[GetChosenInstitution()].append(agent);
			record["posDepartment"] = LIST_DATA[GetChosenInstitution()].size() - 1;
		}
		else {
			LIST_DATA[GetChosenInstitution()].insert(CHOSEN_DEPARTMENT + 1, agent);
			record["posDepartment"] = CHOSEN_DEPARTMENT;
		}
		break;

	case EDIT_CHANGE:
		record["token"] = "ChangeDepartment"; //兼容撤回功能
		record["posDepartment"] = CHOSEN_DEPARTMENT;

		LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["name"] = tmpName;
		break;
	}

	pListChosen->resetData(LIST_DATA[GetChosenInstitution()]);
	pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]);

	BACK_STACK.append(record);//兼容撤回功能

	free(tmpName);
	department_cancel_onclick();
}

void reg_confirm_onclick() {
	if (pTextboxRegPassword->GetText() != pTextboxRegRePassword->GetText()) {
		MessageBox(hwnd, L"两次输入的密码不相同！", L"警告", MB_OKCANCEL);
		return;
	}
	delete(REGISTER_TIP);
	string re = Register(pTextboxRegAccount->GetText(), pTextboxRegPassword->GetText(), pTextboxRegEmail->GetText(), pTextboxRegCheckcode->GetText());
	REGISTER_TIP = CharArrToLPCTSTR(re.c_str());
}

void reg_cancel_onclick() {
	pTextboxRegAccount->ClearText();
	pTextboxRegPassword->ClearText();
	pTextboxRegRePassword->ClearText();
	pTextboxRegEmail->ClearText();
	pTextboxRegCheckcode->ClearText();
	UIinterface = LOGIN_UI;
}

void get_onclick() {
	if (pTextboxRegPassword->GetText() != pTextboxRegRePassword->GetText()) {
		MessageBox(hwnd, L"两次输入的密码不相同！", L"警告", MB_OKCANCEL);
		return;
	}
	delete(REGISTER_TIP);
	string re = Get(pTextboxRegAccount->GetText(), pTextboxRegPassword->GetText(), pTextboxRegEmail->GetText(), pTextboxRegCheckcode->GetText());
	REGISTER_TIP = CharArrToLPCTSTR(re.c_str());
}

void to_tree_onclick() {
	UIinterface = TREE_UI;
}

void to_manager_onclick() {
	UIinterface = MANEGER_UI;
}

void backup_onclick() {
	SaveJson();
	system("data\\BackupManager.exe");
	LoadJson();
}

void retract_onclick() {
	int size = BACK_STACK.size();
	if (size == 0) {
		return;
	}
	Json::Value record = BACK_STACK[size - 1];
	string token = record["token"].asString();
	cout << record.toStyledString() << endl;
	Json::Value tmp = NULL;
	if (token == "AddAgent") {
		string posInstitution = record["posInstitution"].asString();
		int posDepartment = record["posDepartment"].asInt();
		int posAgent = record["posAgent"].asInt();
		cout << posAgent << endl;
		LIST_DATA[posInstitution][posDepartment]["agents"].removeIndex(posAgent, &tmp);
	}
	else if (token == "DeleteAgent") {
		string posInstitution = record["posInstitution"].asString();
		int posDepartment = record["posDepartment"].asInt();
		int posAgent = record["posAgent"].asInt();
		LIST_DATA[posInstitution][posDepartment]["agents"].insert(posAgent + 1, record["data"]);
	}
	else if (token == "ChangeAgent") {
		string posInstitution = record["posInstitution"].asString();
		int posDepartment = record["posDepartment"].asInt();
		int posAgent = record["posAgent"].asInt();
		LIST_DATA[posInstitution][posDepartment]["agents"].removeIndex(posAgent, &tmp);
		LIST_DATA[posInstitution][posDepartment]["agents"].insert(posAgent, record["data"]);
	}
	else if (token == "AddDepartment") {
		string posInstitution = record["posInstitution"].asString();
		int posDepartment = record["posDepartment"].asInt();
		LIST_DATA[posInstitution].removeIndex(posDepartment, &tmp);
	}
	else if (token == "DeleteDepartment") {
		string posInstitution = record["posInstitution"].asString();
		int posDepartment = record["posDepartment"].asInt();
		//if (posDepartment != 0)posDepartment += 1;
		LIST_DATA[posInstitution].insert(posDepartment, record["data"]);
	}
	else if (token == "ChangeDepartment") {
		string posInstitution = record["posInstitution"].asString();
		int posDepartment = record["posDepartment"].asInt();
		LIST_DATA[posInstitution][posDepartment]["name"] = record["data"];
	}


	BACK_STACK.removeIndex(size - 1, &tmp);
	pListChosen->resetData(LIST_DATA[GetChosenInstitution()]);
	pListTable->resetData(LIST_DATA[GetChosenInstitution()][CHOSEN_DEPARTMENT]["agents"]);
}