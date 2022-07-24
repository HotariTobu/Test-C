#pragma once

//寸法A、Bからrateを求める。

#include "windows.h"
#include <stdio.h>
#include <math.h>

// クリップボードにテキストデータをコピーする関数
BOOL SetClipboardText(const char *Str)
{
	int    BufSize;
	char  *Buf;
	HANDLE hMem;

	BufSize = strlen(Str) + 1;                               // 確保するメモリのサイズを計算する
	hMem = GlobalAlloc(GMEM_SHARE | GMEM_MOVEABLE, BufSize); // 移動可能な共有メモリを確保する
	if (!hMem) return FALSE;

	Buf = (char *)GlobalLock(hMem); // 確保したメモリをロックし，アクセス可能にする
	if (Buf)
	{
		strcpy_s(Buf, BufSize, Str);   // 文字列を複写する
		GlobalUnlock(hMem); // メモリのロックを解除する
		if (OpenClipboard(NULL))
		{
			EmptyClipboard();                  // クリップボード内の古いデータを解放する
			SetClipboardData(CF_TEXT, hMem); // クリップボードに新しいデータを入力する
			CloseClipboard();

			return TRUE;
		}
	}
	return FALSE;
}

int entry() {
	int a = 0;
	int b = 0;
	printf_s("a = ");
	scanf_s("%d", &a);
	printf_s("b = ");
	scanf_s("%d", &b);
	char* str = "000000000000";
	sprintf_s(str, 8, "%f1.5", (b * 1.9021130325903 - a * 0.30901699437495) / (a * 0.98768834059514 - b * 0.31286893008046));
	SetClipboardText(str);

	return 0;
}