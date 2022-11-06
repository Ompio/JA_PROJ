#pragma once

#define EXPORT extern "C" __declspec(dllexport)

EXPORT int FProc(); 
EXPORT int FProc_int(int);