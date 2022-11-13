#include "data.h"


LPCTSTR charArrToLPCTSTR(const char* ch) {
	int byteSize = MultiByteToWideChar(0, 0, ch, -1, NULL, 0);
	wchar_t* wideStr = new wchar_t[byteSize];
	MultiByteToWideChar(0, 0, ch, -1, wideStr, byteSize);
	return wideStr;
}

char* intToCstr(unsigned int n) {
	int size = 0;
	int tmp = n;
	while (tmp) {
		++size;
		tmp /= 10;
	}
	char* re = (char*)malloc((size + 1) * sizeof(char));
	for (int i = size - 1; i >= 0; --i) {
		re[i] = n % 10 + '0';
		n /= 10;
	}
	return re;
}