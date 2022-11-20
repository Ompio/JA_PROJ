#include "pch.h"
#include "mydll.h"
#include <iostream>

int FProc_test() {
	return 20;
}
void FProc(BYTE* in, BYTE* out)
{
	*out = 0;	//B
	out++;
	*out = 255; //G
	out++;
	*out = 0;	//R
}
int FProc(int* x) {
	return (int)x;
}