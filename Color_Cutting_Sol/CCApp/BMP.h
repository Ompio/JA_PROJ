#ifndef BMP_H
#define BMP_H
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <vector>

struct BMP
{
	PBITMAPFILEHEADER  file_header;
	PBITMAPINFOHEADER  info_header;
	int picture_size;
	char* data;
	BYTE* pixels;
};

void readBMP(BMP* bmp, const char* file_name);
void saveBMP(BMP* bmp, const char* file_name);
bool checkFile(const char* file_name);
long long run(const char* ifile_name, const char* ofile_name, const int numberofThreads, bool dllType);
long long Blur_run(HINSTANCE library, BMP* bmp, short threadNumber);
HINSTANCE loadLibrary(bool type);
void Time(System::Windows::Forms::TextBox^ ShowTime, std::string newMeasure, bool isCppChosen);
void MarshalString(System::String^ s, std::string& os);
void MarshalString(System::String^ s, std::wstring& os);

#endif