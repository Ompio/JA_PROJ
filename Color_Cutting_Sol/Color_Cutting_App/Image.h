#pragma once

#include <fstream>
#include <iostream>
#include <Windows.h>

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

