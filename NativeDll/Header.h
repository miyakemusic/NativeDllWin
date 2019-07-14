#pragma once
#ifdef NATIVEDLL_EXPORTS
#define NATIVEDLL_API __declspec(dllexport)
#else
#define NATIVEDLL_API __declspec(dllimport)
#endif



extern "C" NATIVEDLL_API bool writeBlock(unsigned long addr, unsigned char* data, int size);
extern "C" NATIVEDLL_API bool writeReg32(unsigned long addr, unsigned int data);

extern "C" NATIVEDLL_API unsigned int readReg32(unsigned long addr);
extern "C" NATIVEDLL_API bool readBlock(unsigned long addr, unsigned char* data, int size);
extern "C" NATIVEDLL_API int waitInterrupt();