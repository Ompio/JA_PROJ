﻿
#include <windows.h> 
#include <stdio.h> 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>


using namespace std;

typedef int(__cdecl* MYPROC)(int*); //definicja typu wskaznika
typedef int(__cdecl* MYPROC2)(int); //definicja typu wskaznika
typedef unsigned char byte; //Użyj BYTE zamiast 

struct BMPFile {
    int height;
    int width;
    const char* filename;
    byte* pixels;
    byte* data;

    BMPFile(const char* filename) {
        //FILE* f = fopen(filename, "rb");
        this->filename = filename;
        fstream f("k.bmp", ios::binary || ios::in);
        if (f) {
            data = new byte[54];
            f.read((char*)data, 54);



            memcpy(&width, data + 18, sizeof(int));
            memcpy(&height, data + 22, sizeof(int));
            //dopytać na zajęciach jaką funkcją to zamienić

            int size = ((width * 3 + 3) & (~3)) * height; //padding
            pixels = new byte[size];
            f.read((char*)pixels, size);
        }
        else {
            cout << "we got nothing";
        }

        f.close();
        //unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel

        //fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once

        //fclose(f);
    }
};

int main(void)
{
    HINSTANCE hinstLib; //obiekt przechowujacy biblioteke z ktorej przechwycimy procedure
    MYPROC ProcAdd; //typ wskaznika na funkcje z argumentami wyzej
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

    // Get a handle to the DLL module.

    hinstLib = LoadLibrary(TEXT("Dll_ASM.dll")); //zaladowanie biblioteki do obiektu

    // If the handle is valid, try to get the function address.
    if (hinstLib != NULL) //sprawdzamy czy biblioteka sie zaladowala
    {
        ProcAdd = (MYPROC)GetProcAddress(hinstLib, "FProc"); //zaladowanie funkcji FProc z biblioteki do wskaznika
        // If the function address is valid, call the function.
        if (NULL != ProcAdd) //sprawdzamy czy funkcja sie zaladowala dobrze
        {
            fRunTimeLinkSuccess = TRUE;

            int* ptr = new int(35);
            
            cout << "value: " << ProcAdd(ptr);


            //Threads
            int threadNumber;
            cin >> threadNumber;
            std::vector<std::thread> threads;
            auto startT = chrono::high_resolution_clock::now();
            for (int i = 0; i < threadNumber; i++) {
                ptr = new int(i);
                threads.push_back(std::thread([&ProcAdd, ptr]() {
                    cout << "hi im thread: " << std::this_thread::get_id() << "and the value i get is: " << ProcAdd(ptr) << endl;
                }));
            }
            for (auto& t : threads) t.join();
            auto stopT = chrono::high_resolution_clock::now();

            //

            auto startF = chrono::high_resolution_clock::now();
            for (int i = 0; i < threadNumber; i++) {
                ptr = new int(i);
                cout << "hi im: "<< i << " function call: "<< ProcAdd(ptr) << endl;
            }
            auto stopF = chrono::high_resolution_clock::now();
            auto durationT = chrono::duration_cast<std::chrono::microseconds>(stopT - startT);
            auto durationF = chrono::duration_cast<std::chrono::microseconds>(stopF - startF);
            cout << "time elapsed from start to end for threads: " << durationT.count() << " and for for: " << durationF.count() << endl;
        }
        // Free the DLL module.
        fFreeResult = FreeLibrary(hinstLib); //na koniec programu, zwalnia wskaznik na biblioteke a zarazem wszystko z nia zwiazane
    }

    



    //fragment z cpp

    HINSTANCE hinstLibC; //obiekt przechowujacy biblioteke z ktorej przechwycimy procedure
    MYPROC2 ProcAddC; //typ wskaznika na funkcje z argumentami wyzej
    BOOL fFreeResultC, fRunTimeLinkSuccessC = FALSE;

    // Get a handle to the DLL module.

    hinstLibC = LoadLibrary(TEXT("Dll_CPP.dll")); //zaladowanie biblioteki do obiektu

    // If the handle is valid, try to get the function address.

    if (hinstLibC != NULL) //sprawdzamy czy biblioteka sie zaladowala
    {
        ProcAddC = (MYPROC2)GetProcAddress(hinstLibC, "FProc_int"); //zaladowanie funkcji FProc z biblioteki do wskaznika
        // If the function address is valid, call the function.
        if (NULL != ProcAddC) //sprawdzamy czy funkcja sie zaladowala dobrze
        {
            fRunTimeLinkSuccessC = TRUE;
            int i = 13;
            std::cout << " " << ProcAddC(13);
        }
        // Free the DLL module.
        fFreeResultC = FreeLibrary(hinstLibC); //na koniec programu, zwalnia wskaznik na biblioteke a zarazem wszystko z nia zwiazane
    }


    // If unable to call the DLL function, use an alternative.
    if (!fRunTimeLinkSuccess)
        printf("Message printed from executable\n");
    if (!fRunTimeLinkSuccessC)
        printf(" C message printed from executable\n");

    //BMP and threads
    BMPFile test("k.bmp");
    /*
    std::fstream plik;
    plik.open("omg.txt", ios::in);
  
    if (plik) {
        cout << "heklkp";
    }*/
    //Loading BMP
    //Threads to DLL's

    //Results to output
    //plik.close();

    return 0;

}