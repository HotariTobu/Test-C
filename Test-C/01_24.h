#pragma once

//シンセサイザーサンプル

#include <Windows.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

int entry() {
	int hz = 48000;//サンプリングレート
	int seconds = hz * 5u;//音の時間
	std::vector<int> data;

	float frq = 1.0f / 440.0f;//平均律による基準の音の周波数
	for (int i = 0; i < seconds; i++) {
		float a = 12767 * sin((float)(2.0f * M_PI * frq * i / hz));
		data.push_back((int)(12767 * sinf((float)(2.0f * M_PI * frq * i / hz))));//波形をプロットし、値を格納する。この段階でバッファの対応する値以上になった場合、波形が断絶し、正常に再生がされないケースあり。最悪スピーカを破損するケースがあるため、取扱には注意が必要。
	}

	LPSTR buffer = new CHAR(data.size());
	PCHAR pBuffer = buffer;
	size_t CHARSize = sizeof(CHAR);
	for (auto i = data.begin(); i != data.end(); i++) {
		*pBuffer = (CHAR)(*i);
		pBuffer += (int)CHARSize;
	}

	WAVEFORMATEX wf;
	wf.wFormatTag = WAVE_FORMAT_PCM;//形式
	wf.nChannels = 2;//モノラルは'1' ステレオなら'2'。
	wf.nSamplesPerSec = hz;//サンプリングレート
	wf.wBitsPerSample = 16;//16ビット
	wf.nBlockAlign = wf.nChannels * wf.wBitsPerSample / 8;//計算
	wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;//計算
	wf.cbSize = 0;//計算

	HWAVEOUT hWOut;//デバイス

	MMRESULT wooR = waveOutOpen(&hWOut, WAVE_MAPPER, &wf, 0, 0, CALLBACK_NULL);//デバイスを開く
	if (wooR != MMSYSERR_NOERROR) {
		WCHAR etb[1024];
		waveOutGetErrorText(wooR, etb, sizeof(WCHAR) * sizeof(etb));
		return -1;
	}

	WAVEHDR wh;
	wh.lpData = buffer;//  データを書き込む
	wh.dwBufferLength = sizeof(short) * wf.nChannels * seconds;//再生時間
	wh.dwFlags = 0;//追加のオプション
	wh.dwLoops = 1;//1回だけ再生
	wh.dwBytesRecorded = 0;//音声入力の時に使う
	wh.dwUser = 0;//オプションのユーザーデータ
	wh.lpNext = NULL;//使われない
	wh.reserved = 0;//使われない

	MMRESULT wophR = waveOutPrepareHeader(hWOut, &wh, sizeof(WAVEHDR));//バッファの準備
	if (wophR != MMSYSERR_NOERROR) {
		return -2;
	}

	MMRESULT wowR = waveOutWrite(hWOut, &wh, sizeof(WAVEHDR));//再生
	if (wowR != MMSYSERR_NOERROR) {
		return -3;
	}

	system("pause");

	MMRESULT worR = waveOutReset(hWOut);//停止
	if (worR != MMSYSERR_NOERROR) {
		return -4;
	}

	MMRESULT wouhR = waveOutUnprepareHeader(hWOut, &wh, sizeof(WAVEHDR));//バッファの解放
	if (wouhR != MMSYSERR_NOERROR) {
		return - 5;
	}

	MMRESULT wocR = waveOutClose(hWOut);//デバイスの解放
	if (wocR != MMSYSERR_NOERROR) {
		return -7;
	}

	/*****************************************************************************************************************/

	/*short wav_hz = 44100;// サンプリングレート
	unsigned int musictime = wav_hz * 5;
	short* wave_data = (short*)GlobalAlloc(GPTR, sizeof(short)*musictime);

	float frq = 1.f / 440.f;  //平均律による基準の音、の周波数
	for (int t = 0; t<musictime; t++) {
		//波形をプロットし、値を格納する。
		//この段階でバッファの対応する値以上になった場合、
		//波形が断絶し、正常に再生がされないケースあり。
		//最悪スピーカを破損するケースがあるため、取扱には注意が必要。
		float a = 12767 * sin((float)(2.0f * M_PI * frq * t / wav_hz));
		wave_data[t]
			= (short)(12767 * sinf((FLOAT)(2.0f*M_PI*frq*t / wav_hz)));
	}

	WAVEFORMATEX wf;                              //WAVEFORMATEX 構造体
	wf.wFormatTag = WAVE_FORMAT_PCM;                //変更しなくてもいいや
	wf.nChannels = 1;          //モノラルは'1' ステレオなら'2'。
	wf.nSamplesPerSec = 44100;        //44100Hz
	wf.wBitsPerSample = 16;                         //16ビット
	wf.nBlockAlign = wf.nChannels*wf.wBitsPerSample / 8;       //計算
	wf.nAvgBytesPerSec = wf.nSamplesPerSec*wf.nBlockAlign;   //計算
	wf.cbSize = 0;                                           //計算
	HWAVEOUT hWOut;
	//コールバックにも対応しているが、今回は実装しない
	waveOutOpen(&hWOut, WAVE_MAPPER, &wf, 0, 0, CALLBACK_NULL);

	WAVEHDR wh;
	wh.lpData = (LPSTR)wave_data;   //  データを書き込む
	wh.dwBufferLength = sizeof(short)*wf.nChannels*musictime;//再生時間
	wh.dwFlags = 0;
	wh.dwLoops = 1;//1回だけ再生
	wh.dwBytesRecorded = 0;
	wh.dwUser = 0;
	wh.lpNext = NULL;
	wh.reserved = 0;

	//  再生
	waveOutPrepareHeader(hWOut, &wh, sizeof(WAVEHDR));
	waveOutWrite(hWOut, &wh, sizeof(WAVEHDR));*/

	return 0;
}