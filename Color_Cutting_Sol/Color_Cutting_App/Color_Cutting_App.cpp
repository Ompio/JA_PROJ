
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
#include "Image.h"


//using namespace std;

typedef void(__cdecl* MYPROC)(BYTE*, BYTE*, BYTE*); //definicja typu wskaznika

int main(void)
{
    HINSTANCE hinstLib; //obiekt przechowujacy biblioteke z ktorej przechwycimy procedure
    MYPROC ProcAdd; //typ wskaznika na funkcje z argumentami wyzej
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
    bool useCpp = false;
    BMPFile* FileA;
    BMPFile* FileB;
    FileA = new BMPFile("understanding.bmp");  // BMPFile* FileB("c.bmp");
    FileB = new BMPFile(*FileA);
    
    // Get a handle to the DLL module.
    if (useCpp) {
        hinstLib = LoadLibrary(TEXT("Dll_CPP.dll"));
    }
    else {
        hinstLib = LoadLibrary(TEXT("Dll_ASM.dll")); //zaladowanie biblioteki do obiektu
    }
    // If the handle is valid, try to get the function address.
    if (hinstLib != NULL) //sprawdzamy czy biblioteka sie zaladowala
    {
        ProcAdd = (MYPROC)GetProcAddress(hinstLib, "FProc"); //zaladowanie funkcji FProc 
        //z biblioteki do wskaznika
        // If the function address is valid, call the function.
        if (NULL != ProcAdd) //sprawdzamy czy funkcja sie zaladowala dobrze
        {
            fRunTimeLinkSuccess = TRUE;

           // std::cout << "value: " << ProcAdd(ptr);
            int threadNumber = 3;
            int szer = FileA->infoHeader->biWidth;
            int wys = FileA->infoHeader->biHeight;
            int numpixels = szer * wys;
           
            int padding = 0;
            if ((szer * 3) % 4 != 0)
            {
                padding = 4 - szer % 4;
            }
            int alliterations = (szer + padding) * wys;
            byte* PixelA = FileA->pixels + 1; //B
            byte* PixelB = FileB->pixels;

            //tablica byte na zmiane koloru 3 elementowa i inkrementacja pierwszego byte w funkcji
            byte colorToSeek[3] = { 29     //Wartość B
                                    ,230   //Wartość G
                                    ,181 };  //Wartość R

            std::cout << (int) colorToSeek[0] << " " << (int)(colorToSeek[1]) << " " << (int)(colorToSeek[2]) << std::endl;
            
            byte colorChanged[3] = { 255    //Wartość B
                                     ,250     //Wartość G
                                     ,150 };   //Wartość R

            for (int i = 0; i < alliterations; i++) {
                ProcAdd(PixelB + i * 3, colorToSeek, colorChanged);
            }
            
            std::cout << "wys: " << wys << " szer: " << szer << " numpixels: " << numpixels << " PixelA: " << *PixelA << std::endl;
       
            std::vector<std::thread> threads;
            auto startT = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < threadNumber; i++) {
                threads.push_back(std::thread([&ProcAdd, &PixelA, &PixelB, i]() {
                    
                    }));
            }
            for (auto& t : threads) t.join();
            auto stopT = std::chrono::high_resolution_clock::now();
            auto durationT = std::chrono::duration_cast<std::chrono::microseconds>(stopT - startT);
            std::cout << "time elapsed from start to end for threads: " << durationT.count() << std::endl;
        }
        fFreeResult = FreeLibrary(hinstLib); //na koniec programu, 
        //zwalnia wskaznik na biblioteke a zarazem wszystko z nia zwiazane
    }

    if (!fRunTimeLinkSuccess)
        printf("Message printed from executable\n");
    
    FileB->saveFile("c.bmp");


    //BMP
    

    return 0;

}