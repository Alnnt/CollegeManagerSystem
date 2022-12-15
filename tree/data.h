#pragma once
#include <easyx.h>
#include <string>
#include <json/json.h>
#include <fstream>

#include <comutil.h>  
#pragma comment(lib, "comsuppw.lib")

void LoadJson();
void SaveJson();

std::string WStoS(const std::wstring& ws);
std::wstring StoWS(const std::string& s);

wchar_t* Utf8ToUnicode(const char* row_i);
char* UnicodeToUtf8(const wchar_t* unicode);

LPCTSTR CharArrToLPCTSTR(const char* ch);    //C��ʽ�ַ�����תLPCTSTR���ַ�ָ��
char* LpctstrToCharArr(LPCTSTR pwszUnicode); //LPCTSTR���ַ�ָ��תC��ʽ�ַ�����

char* IntToCstr(unsigned int n);             //������תC��ʽ�ַ�����
