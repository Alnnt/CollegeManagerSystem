#pragma once
#include "common.h"
#include <Windows.h>


//void FlushMove(int decX);

/// <summary>
///	²¥·Å°´Å¥µ¥»÷ÒôÐ§
/// </summary>
void PlayClickSound(void);

/// <summary>
///	´°¿ÚÎÞ±ß¿ò²¢Ô²½Ç»¯
/// </summary>
/// <param name="radius">Ô²½Ç°ë¾¶</param>
void EnRoundWindows(HWND hwnd, int radius);

/// <summary>
/// »æÖÆÍ¸Ã÷±³¾°PNGÍ¼Æ¬
/// </summary>
/// <param name="picture"></param>
/// <param name="picture_x"></param>
/// <param name="picture_y"></param>
void DrawAlpha(int  picture_x, int picture_y, IMAGE* picture);

/// <summary>
/// Êä³ö°ëÍ¸Ã÷Í¼Æ¬
/// </summary>
/// <param name="dstx">X×ø±ê</param>
/// <param name="dsty">Y×ø±ê</param>
/// <param name="img">Í¼Æ¬</param>
/// <param name="color"></param>
/// <param name="alpha"></param>
void PutPicture(int dstx, int dsty, IMAGE* img, COLORREF color, int alpha);