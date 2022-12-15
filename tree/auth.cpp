#include "auth.h"
#include "data.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "RsaEncode.h"
using namespace std;

string HttpGet(string body);
string GENERATED_CHECK_CODE = "None";
LPCTSTR LOGIN_TIP;
LPCTSTR REGISTER_TIP;

Permission PERMISSION = Common;
string PER_DEPARTMENT = "None";


//HttpGet("/content")
string Login(wstring account,wstring password) {
	string sendAccount(UnicodeToUtf8(account.c_str()));
	
	//cout << "Request: " << "/cms/cms.php?account=" + sendAccount + "&password=" + WStoS(password) + "&type=log" << endl;
	string re = HttpGet("/cms/cms.php?account=" + sendAccount + "&password=" + RsaPublicEncode(WStoS(password)) + "&type=log");
	//cout << "Re: " << re << endl;
	//cout << "/cms/cms.php?account=" + WStoS(account) + "&password=" + WStoS(password) + "&type=log" << endl;
	wstring tmp(Utf8ToUnicode(re.c_str()));
	return WStoS(tmp);
	//return re;
	//return "";
}

string Register(wstring account, wstring password, wstring email, wstring CheckCode) {
	string sendAccount(UnicodeToUtf8(account.c_str()));
	cout << "Request: " << "/cms/cms.php?account=" + sendAccount + "&password=" + RsaPublicEncode(WStoS(password)) + "&type=reg&email=" + WStoS(email) + "&CheckCode=" + GENERATED_CHECK_CODE << endl;
	string re = HttpGet("/cms/cms.php?account=" + sendAccount + "&password=" + RsaPublicEncode(WStoS(password)) + "&type=reg&email=" + WStoS(email) + "&CheckCode=" + WStoS(CheckCode));
	//cout << "Re: "  << re << endl << endl;
	
	wstring tmp(Utf8ToUnicode(re.c_str()));
	return WStoS(tmp);
	//return re;
	//return "";
}

string Get(wstring account, wstring password, wstring email, wstring CheckCode) {
	string sendAccount(UnicodeToUtf8(account.c_str()));
	string re = HttpGet("/cms/cms.php?account=" + sendAccount + "&password=" + RsaPublicEncode(WStoS(password)) + "&type=get&email=" + WStoS(email) + "&CheckCode=" + GENERATED_CHECK_CODE);
	wstring tmp(Utf8ToUnicode(re.c_str()));
	return WStoS(tmp);
}

void GeneratCheckCode() {
	srand(time(0));
	string CheckCode;
	for (int i = 0; i < 6; ++i) {
		int tmp = rand() % 3;
		if (tmp == 0) {  //生成数字
			CheckCode.push_back((char)(rand() % 10 + 48));
		}
		else {            //生成字母
			CheckCode.push_back((char)(rand() % 26 + 65));
		}
	}
	GENERATED_CHECK_CODE = CheckCode;
	//cout << GENERATED_CHECK_CODE;
}