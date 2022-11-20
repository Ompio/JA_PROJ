#pragma once

#define EXPORT extern "C" __declspec(dllexport)

EXPORT int FProc_test(); 
EXPORT void FProc(BYTE*,BYTE*);