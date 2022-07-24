#pragma once

//���@A�AB����rate�����߂�B

#include "windows.h"
#include <stdio.h>
#include <math.h>

// �N���b�v�{�[�h�Ƀe�L�X�g�f�[�^���R�s�[����֐�
BOOL SetClipboardText(const char *Str)
{
	int    BufSize;
	char  *Buf;
	HANDLE hMem;

	BufSize = strlen(Str) + 1;                               // �m�ۂ��郁�����̃T�C�Y���v�Z����
	hMem = GlobalAlloc(GMEM_SHARE | GMEM_MOVEABLE, BufSize); // �ړ��\�ȋ��L���������m�ۂ���
	if (!hMem) return FALSE;

	Buf = (char *)GlobalLock(hMem); // �m�ۂ��������������b�N���C�A�N�Z�X�\�ɂ���
	if (Buf)
	{
		strcpy_s(Buf, BufSize, Str);   // ������𕡎ʂ���
		GlobalUnlock(hMem); // �������̃��b�N����������
		if (OpenClipboard(NULL))
		{
			EmptyClipboard();                  // �N���b�v�{�[�h���̌Â��f�[�^���������
			SetClipboardData(CF_TEXT, hMem); // �N���b�v�{�[�h�ɐV�����f�[�^����͂���
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