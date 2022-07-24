#pragma once

//�V���Z�T�C�U�[�T���v��

#include <Windows.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

int entry() {
	int hz = 48000;//�T���v�����O���[�g
	int seconds = hz * 5u;//���̎���
	std::vector<int> data;

	float frq = 1.0f / 440.0f;//���ϗ��ɂ���̉��̎��g��
	for (int i = 0; i < seconds; i++) {
		float a = 12767 * sin((float)(2.0f * M_PI * frq * i / hz));
		data.push_back((int)(12767 * sinf((float)(2.0f * M_PI * frq * i / hz))));//�g�`���v���b�g���A�l���i�[����B���̒i�K�Ńo�b�t�@�̑Ή�����l�ȏ�ɂȂ����ꍇ�A�g�`���f�₵�A����ɍĐ�������Ȃ��P�[�X����B�ň��X�s�[�J��j������P�[�X�����邽�߁A�戵�ɂ͒��ӂ��K�v�B
	}

	LPSTR buffer = new CHAR(data.size());
	PCHAR pBuffer = buffer;
	size_t CHARSize = sizeof(CHAR);
	for (auto i = data.begin(); i != data.end(); i++) {
		*pBuffer = (CHAR)(*i);
		pBuffer += (int)CHARSize;
	}

	WAVEFORMATEX wf;
	wf.wFormatTag = WAVE_FORMAT_PCM;//�`��
	wf.nChannels = 2;//���m������'1' �X�e���I�Ȃ�'2'�B
	wf.nSamplesPerSec = hz;//�T���v�����O���[�g
	wf.wBitsPerSample = 16;//16�r�b�g
	wf.nBlockAlign = wf.nChannels * wf.wBitsPerSample / 8;//�v�Z
	wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;//�v�Z
	wf.cbSize = 0;//�v�Z

	HWAVEOUT hWOut;//�f�o�C�X

	MMRESULT wooR = waveOutOpen(&hWOut, WAVE_MAPPER, &wf, 0, 0, CALLBACK_NULL);//�f�o�C�X���J��
	if (wooR != MMSYSERR_NOERROR) {
		WCHAR etb[1024];
		waveOutGetErrorText(wooR, etb, sizeof(WCHAR) * sizeof(etb));
		return -1;
	}

	WAVEHDR wh;
	wh.lpData = buffer;//  �f�[�^����������
	wh.dwBufferLength = sizeof(short) * wf.nChannels * seconds;//�Đ�����
	wh.dwFlags = 0;//�ǉ��̃I�v�V����
	wh.dwLoops = 1;//1�񂾂��Đ�
	wh.dwBytesRecorded = 0;//�������͂̎��Ɏg��
	wh.dwUser = 0;//�I�v�V�����̃��[�U�[�f�[�^
	wh.lpNext = NULL;//�g���Ȃ�
	wh.reserved = 0;//�g���Ȃ�

	MMRESULT wophR = waveOutPrepareHeader(hWOut, &wh, sizeof(WAVEHDR));//�o�b�t�@�̏���
	if (wophR != MMSYSERR_NOERROR) {
		return -2;
	}

	MMRESULT wowR = waveOutWrite(hWOut, &wh, sizeof(WAVEHDR));//�Đ�
	if (wowR != MMSYSERR_NOERROR) {
		return -3;
	}

	system("pause");

	MMRESULT worR = waveOutReset(hWOut);//��~
	if (worR != MMSYSERR_NOERROR) {
		return -4;
	}

	MMRESULT wouhR = waveOutUnprepareHeader(hWOut, &wh, sizeof(WAVEHDR));//�o�b�t�@�̉��
	if (wouhR != MMSYSERR_NOERROR) {
		return - 5;
	}

	MMRESULT wocR = waveOutClose(hWOut);//�f�o�C�X�̉��
	if (wocR != MMSYSERR_NOERROR) {
		return -7;
	}

	/*****************************************************************************************************************/

	/*short wav_hz = 44100;// �T���v�����O���[�g
	unsigned int musictime = wav_hz * 5;
	short* wave_data = (short*)GlobalAlloc(GPTR, sizeof(short)*musictime);

	float frq = 1.f / 440.f;  //���ϗ��ɂ���̉��A�̎��g��
	for (int t = 0; t<musictime; t++) {
		//�g�`���v���b�g���A�l���i�[����B
		//���̒i�K�Ńo�b�t�@�̑Ή�����l�ȏ�ɂȂ����ꍇ�A
		//�g�`���f�₵�A����ɍĐ�������Ȃ��P�[�X����B
		//�ň��X�s�[�J��j������P�[�X�����邽�߁A�戵�ɂ͒��ӂ��K�v�B
		float a = 12767 * sin((float)(2.0f * M_PI * frq * t / wav_hz));
		wave_data[t]
			= (short)(12767 * sinf((FLOAT)(2.0f*M_PI*frq*t / wav_hz)));
	}

	WAVEFORMATEX wf;                              //WAVEFORMATEX �\����
	wf.wFormatTag = WAVE_FORMAT_PCM;                //�ύX���Ȃ��Ă�������
	wf.nChannels = 1;          //���m������'1' �X�e���I�Ȃ�'2'�B
	wf.nSamplesPerSec = 44100;        //44100Hz
	wf.wBitsPerSample = 16;                         //16�r�b�g
	wf.nBlockAlign = wf.nChannels*wf.wBitsPerSample / 8;       //�v�Z
	wf.nAvgBytesPerSec = wf.nSamplesPerSec*wf.nBlockAlign;   //�v�Z
	wf.cbSize = 0;                                           //�v�Z
	HWAVEOUT hWOut;
	//�R�[���o�b�N�ɂ��Ή����Ă��邪�A����͎������Ȃ�
	waveOutOpen(&hWOut, WAVE_MAPPER, &wf, 0, 0, CALLBACK_NULL);

	WAVEHDR wh;
	wh.lpData = (LPSTR)wave_data;   //  �f�[�^����������
	wh.dwBufferLength = sizeof(short)*wf.nChannels*musictime;//�Đ�����
	wh.dwFlags = 0;
	wh.dwLoops = 1;//1�񂾂��Đ�
	wh.dwBytesRecorded = 0;
	wh.dwUser = 0;
	wh.lpNext = NULL;
	wh.reserved = 0;

	//  �Đ�
	waveOutPrepareHeader(hWOut, &wh, sizeof(WAVEHDR));
	waveOutWrite(hWOut, &wh, sizeof(WAVEHDR));*/

	return 0;
}