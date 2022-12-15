#pragma once
#include "common.h"
#include <Windows.h>


//void FlushMove(int decX);

/// <summary>
///	���Ű�ť������Ч
/// </summary>
void PlayClickSound(void);

/// <summary>
///	�����ޱ߿�Բ�ǻ�
/// </summary>
/// <param name="radius">Բ�ǰ뾶</param>
void EnRoundWindows(HWND hwnd, int radius);

/// <summary>
/// ����͸������PNGͼƬ
/// </summary>
/// <param name="picture"></param>
/// <param name="picture_x"></param>
/// <param name="picture_y"></param>
void DrawAlpha(int  picture_x, int picture_y, IMAGE* picture);

/// <summary>
/// �����͸��ͼƬ
/// </summary>
/// <param name="dstx">X����</param>
/// <param name="dsty">Y����</param>
/// <param name="img">ͼƬ</param>
/// <param name="color"></param>
/// <param name="alpha"></param>
void PutPicture(int dstx, int dsty, IMAGE* img, COLORREF color, int alpha);