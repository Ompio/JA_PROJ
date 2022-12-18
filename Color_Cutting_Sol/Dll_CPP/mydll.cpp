#include "pch.h"
#include "mydll.h"
#include <iostream>

int FProc_test() {
	return 20;
}
void FProc(BYTE* pixel, BYTE seekedColor[], BYTE changeColor[])
{
	//*pixel = 124;	//B
	//pixel++;
	//*pixel = 0; //G
	//pixel++;
	//*pixel = 249;	//R 
	//std::cout << (char)seekedColor[0] << (char)seekedColor[1] << (char)seekedColor[2];


	if (*pixel == seekedColor[0] && *(pixel + 1) == seekedColor[1] && *(pixel + 2) == seekedColor[2]) {
		
		*pixel = changeColor[0]; //B
		*(pixel + 1) = changeColor[1]; //G
		*(pixel + 2) = changeColor[2]; //R

	}

}
int FProc(int* x) {
	return (int)x;
}