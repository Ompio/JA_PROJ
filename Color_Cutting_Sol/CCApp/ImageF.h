#pragma once

#include <fstream>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <thread>
#include <chrono>

struct BMPFile
{
    PBITMAPFILEHEADER fileHeader;
    PBITMAPINFOHEADER infoHeader;
    BYTE* data;
    BYTE* pixels;
    size_t dataSize;
    const char* fileName;

public:
    BMPFile(const char* fileName);
    BMPFile(const BMPFile& file);
    ~BMPFile();
    void saveFile();
    void saveFile(const char* fileName);
};
long long run(const char* ifile_name, const char* ofile_name, const int numberofThreads, bool dllType, byte* kolory);
void MarshalString(System::String^ s, std::string& os);
void MarshalString(System::String^ s, std::wstring& os);
