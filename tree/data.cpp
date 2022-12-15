#include "data.h"


Json::Value LIST_DATA;
using namespace std;

std::string WStoS(const std::wstring& ws)
{
	std::string curLocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "chs");
	const wchar_t* _Source = ws.c_str();
	size_t _Dsize = 2 * ws.size() + 1;
	char* _Dest = new char[_Dsize];
	memset(_Dest, 0, _Dsize);
	wcstombs(_Dest, _Source, _Dsize);
	std::string result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}

std::wstring StoWS(const std::string& s)
{
	setlocale(LC_ALL, "chs");
	const char* _Source = s.c_str();
	size_t _Dsize = s.size() + 1;
	wchar_t* _Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, "C");
	return result;
}

wchar_t* Utf8ToUnicode(const char* row_i) //UTF8转unicode
{
	int len = MultiByteToWideChar(CP_UTF8, 0, row_i, strlen(row_i), NULL, 0);
	wchar_t* wszStr = new wchar_t[len + 1];
	MultiByteToWideChar(CP_UTF8, 0, row_i, strlen(row_i), wszStr, len);
	wszStr[len] = '\0';
	return wszStr;
}

char* UnicodeToUtf8(const wchar_t* unicode)
{
	int len;
	len = WideCharToMultiByte(CP_UTF8, 0, unicode, -1, NULL, 0, NULL, NULL);
	char* szUtf8 = (char*)malloc(len + 1);
	memset(szUtf8, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, unicode, -1, szUtf8, len, NULL, NULL);
	return szUtf8;
}


LPCTSTR CharArrToLPCTSTR(const char* ch) {    //调用后请delete
	int byteSize = MultiByteToWideChar(0, 0, ch, -1, NULL, 0);
	wchar_t* wideStr = new wchar_t[byteSize];
	MultiByteToWideChar(0, 0, ch, -1, wideStr, byteSize);
	return wideStr;
}

char* LpctstrToCharArr(LPCTSTR pwszUnicode) {   //调用后请free  - typedef wchar_t* LPCTSTR 
	int iSize = WideCharToMultiByte(CP_ACP, 0, pwszUnicode, -1, NULL, 0, NULL, NULL);  //获取字节大小
	char* pszMultiByte = (char*)malloc(iSize * sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, pwszUnicode, -1, pszMultiByte, iSize, NULL, NULL);
	return pszMultiByte;
}

char* IntToCstr(unsigned int n) {
	int size = 0;
	int tmp = n;
	while (tmp) { //统计位数
		++size;
		tmp /= 10;
	}
	char* re = (char*)malloc((size + 1) * sizeof(char));
	for (int i = size - 1; i >= 0; --i) {
		re[i] = n % 10 + '0';
		n /= 10;
	}
	*(re + size) = '\0';
	return re;
}

void LoadJson() {
	std::ifstream fin("data/data.json");
	Json::Reader reader;
	reader.parse(fin, LIST_DATA, 0);
	fin.close();
}

void SaveJson() {
	std::ofstream fout("data/data.json");
	fout << LIST_DATA.toStyledString();
	fout.close();
}
