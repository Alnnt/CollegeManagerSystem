#include "VisualEffects.h"
#include <windows.h>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")


extern int X_CHOSEN_INSTITUTION;


//void FlushMove(int deX) {
//	int time = 200;
//	int srX = X_CHOSEN_INSTITUTION;
//	int pot = (deX - srX) / 5;
//	if (srX < deX) {
//		while (true) {
//			if (X_CHOSEN_INSTITUTION < srX + pot)
//				X_CHOSEN_INSTITUTION += 10;
//			else if (X_CHOSEN_INSTITUTION < srX + pot * 2)
//				X_CHOSEN_INSTITUTION += 15;
//			else if (X_CHOSEN_INSTITUTION < srX + pot * 3)
//				X_CHOSEN_INSTITUTION += 20;
//			else if (X_CHOSEN_INSTITUTION < srX + pot * 4)
//				X_CHOSEN_INSTITUTION += 15;
//			else if (X_CHOSEN_INSTITUTION < srX + pot * 5)
//				X_CHOSEN_INSTITUTION += 10;
//			else if (X_CHOSEN_INSTITUTION > deX) {
//				X_CHOSEN_INSTITUTION = deX;
//				return;
//			}
//			Sleep(time);
//		}
//	}
//
//}


void PlayClickSound(void) {
	PlaySound(_T("./sounds\\click.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
}

void EnRoundWindows(HWND hwnd, int radius) {
	//设置程序的显示大小及位置
	MoveWindow(hwnd, 100, 100, 1280, 768, false);

	RECT windowsRC;
	GetWindowRect(hwnd, &windowsRC);

	int scrWidth, scrHeight;
	scrWidth = GetSystemMetrics(SM_CXSCREEN);
	scrHeight = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(hwnd, HWND_TOP, (scrWidth - windowsRC.right) / 2, (scrHeight - windowsRC.bottom) / 2, windowsRC.right - windowsRC.left, windowsRC.bottom - windowsRC.top, SWP_SHOWWINDOW);
	//去除边框
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~(WS_CAPTION | WS_SIZEBOX));
	//窗口圆角化
	HRGN hRgn = CreateRoundRectRgn(0, 0, windowsRC.right - windowsRC.left, windowsRC.bottom - windowsRC.top, radius, radius);
	SetWindowRgn(hwnd, hRgn, true);
}


void DrawAlpha(int  picture_x, int picture_y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
{
	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}


void PutPicture(int dstx, int dsty, IMAGE* img, COLORREF color, int alpha) {//0~255 255表示不透明
	DWORD* imgp = GetImageBuffer(img);
	DWORD* bgimgp = GetImageBuffer();
	int w, bw, h, i, j;
	w = img->getwidth();
	bw = getwidth();
	h = img->getheight();
	color += 0xff000000;
	if (alpha < 0)alpha = 0;
	else if (alpha > 255)alpha = 255;
	for (i = 0; i < h; ++i)
		for (j = 0; j < w; ++j)
			if (imgp[i * w + j] != color)
				bgimgp[(i + dsty) * bw + j + dstx] = RGB(
					((int)(alpha / 255.0 * GetRValue(imgp[i * w + j]) + (1 - alpha / 255.0) * GetRValue(bgimgp[(i + dsty) * bw + j + dstx]))),
					((int)(alpha / 255.0 * GetGValue(imgp[i * w + j]) + (1 - alpha / 255.0) * GetGValue(bgimgp[(i + dsty) * bw + j + dstx]))),
					((int)(alpha / 255.0 * GetBValue(imgp[i * w + j]) + (1 - alpha / 255.0) * GetBValue(bgimgp[(i + dsty) * bw + j + dstx])))
				);
}
