// NativeDll.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include "Header.h"

#include<Windows.h>
#include<stdio.h>

HANDLE hThead;
HANDLE hEvent;
DWORD WINAPI Thread1(LPVOID pData) {
	for (int i = 0; i < 5; i++) {
		Sleep(1000);
		printf_s("Thread %d", i);

	}

//	printf_s("Before set Event");
	SetEvent(hEvent);
//	printf_s("After set Event");

	return 0;
}

NATIVEDLL_API bool writeBlock(unsigned long addr, unsigned char* data, int size) {

	printf_s("addr=0x%x, size=%d\n", addr, size);
	return TRUE;
}

NATIVEDLL_API bool writeReg32(unsigned long addr, unsigned int data) {

	printf_s("addr=0x%x, data=%d\n", addr, data);

	if (addr == 0x04 && data == 0x01) {
		hThead = CreateThread(NULL, 0, Thread1, (LPVOID)NULL, 0, NULL);//Thread1を開始		
	}
	return TRUE;
}

NATIVEDLL_API unsigned int readReg32(unsigned long addr) {

	return 0;
}

NATIVEDLL_API bool readBlock(unsigned long addr, unsigned char* data, int size) {

	return TRUE;
}

NATIVEDLL_API int waitInterrupt() {
	printf_s("Before wait\n");
	int ret = WaitForSingleObject(hEvent, INFINITE);
	ResetEvent(hEvent);
	printf_s("After wait %d\n", ret);
	return ret;
}