#include "functions.h"
#include "manager.h"

extern HWND hwnd;
extern TYPE_UI UIinterface;
extern type_ins institutionNow;

extern int x_chosen_institution;

void _CLOSE_onClick(void) {
	exit(0);
}

void _LOGIN_onClick(void) {
	if (pTextboxAccount->GetText() == L"QAQ") {
		MessageBox(hwnd, L"登入成功！", L"提示", MB_OKCANCEL);
	}
	UIinterface = MANEGER_UI;
}

void _REGISTER_onClick(void) {
	UIinterface = REGISTER_UI;
}

void _XSH_onClick(void) {
	institutionNow = IS_XueShengHui;
	x_chosen_institution = 180;
}

void _SL_onClick(void) {
	institutionNow = IS_SheLian;
	x_chosen_institution = 600;
}

void _GC_onClick(void) {
	institutionNow = IS_GeChuang;
	x_chosen_institution = 1000;
}