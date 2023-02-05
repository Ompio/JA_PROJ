
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
    std::fstream fout;
    fout.open("wynikipomiarow.csv", std::ios::out | std::ios::app);
    std::string filename;
    std::string outfilename;
    
        
    for (int l = 3; l <= 3; l++) {
        if (l == 0) {
            filename = "smoll.bmp";
            fout << "smol;" << std::endl;
            outfilename = "cSMOL3.bmp";
        }
        if (l == 1) {
            filename = "Medium.bmp";
            fout << "medium;" << std::endl;
            outfilename = "cMEDIUM.bmp";
        }
        if (l == 2) {
            filename = "BIG.bmp";
            fout << "big;" << std::endl;
            outfilename = "cBIG.bmp";
        }
        if (l == 3) {
            filename = "bardzoduzyplik.bmp";
            fout << "vBig;" << std::endl;
            outfilename = "cVBig.bmp";
        }

        for (int j = 0; j < 2; j++) {
            for (int w = 1; w <= 64; w *= 2) {
                if (j == 0) {
                    fout << w << ";cpp;";
                }
                else fout << w << ";asm;";

                for (int i = 0; i < 100; i++) {

                    HINSTANCE hinstLib; //obiekt przechowujacy biblioteke z ktorej przechwycimy procedure
                    MYPROC ProcAdd; //typ wskaznika na funkcje z argumentami wyzej
                    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
                    bool useCpp;
                    if (j == 0) {
                        useCpp = true;
                    }
                    else useCpp = false;
                    BMPFile* FileA;
                    BMPFile* FileB;
                    FileA = new BMPFile(filename.c_str());  // BMPFile* FileB("c.bmp");
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
                            int threadNumber = w;
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
                            byte colorToSeek[3] = { 79          //Wartość B
                                                    ,13        //Wartość G
                                                    ,248 };     //Wartość R

                            std::cout << (int)colorToSeek[0] << " " << (int)(colorToSeek[1]) << " " << (int)(colorToSeek[2]) << std::endl;

                            byte colorChanged[3] = { 128       //Wartość B
                                                        ,255       //Wartość G
                                                        ,128 };    //Wartość R

                            if (l == 1) {
                                colorToSeek[0] = 79;          //Wartość B
                                colorToSeek[1] = 13;        //Wartość G
                                colorToSeek[2] = 248;     //Wartość R
                            }
                            if (l == 2) {
                                colorToSeek[0] = 79;          //Wartość B
                                colorToSeek[1] = 13;        //Wartość G
                                colorToSeek[2] = 248;     //Wartość R
                            }
                            int threadOffset = alliterations / threadNumber; //może sprawiać problemy gdy ilość threadów i ilosc iteracji będzie się nie zgadzać
                            int lastPixels = alliterations % threadNumber;



                            auto f = [&ProcAdd, &PixelB, &colorToSeek, &colorChanged](int threadNumber, int offset, int  add = 0)
                            {
                                int itCounter = 0;
                                for (int i = 0 + offset * threadNumber; i < offset * (threadNumber + 1) - 1 + add; i += 4) {
                                    ProcAdd(PixelB + i * 3, colorToSeek, colorChanged);
                                    //std::cout << "iteration: " << itCounter << " of thread: " << threadNumber << std::endl;
                                    itCounter++;
                                }
                            };

                            std::vector<std::thread> threads;
                            auto startT = std::chrono::high_resolution_clock::now();
                            for (int i = 0; i < threadNumber; i++) {
                                //std::cout << "thread: " << i << std::endl;
                                if (i == threadNumber - 1) {
                                    threads.push_back(std::thread(f, i, threadOffset, lastPixels));
                                }
                                else threads.push_back(std::thread(f, i, threadOffset));

                            }

                            for (auto& t : threads) t.join();

                            auto stopT = std::chrono::high_resolution_clock::now();

                            if (j == 0) {
                                // std::cout << w << " cpp: ";
                            }
                            else {
                                //std::cout << w << " asm: ";
                            }
                            std::cout << "wys: " << wys << " szer: " << szer << " numpixels: " << numpixels << " alliterations: " << alliterations << " PixelA: " << *PixelA << " lastPixels: " << lastPixels << " threadOffset " << threadOffset << std::endl;



                            auto durationT = std::chrono::duration_cast<std::chrono::microseconds>(stopT - startT);
                            std::cout << "time elapsed: " << durationT.count() << std::endl;
                            fout << durationT.count() << ";";
                        }
                        fFreeResult = FreeLibrary(hinstLib); //na koniec programu, 
                        //zwalnia wskaznik na biblioteke a zarazem wszystko z nia zwiazane
                    }

                    if (!fRunTimeLinkSuccess)
                        printf("Message printed from executable\n");

                    FileB->saveFile(outfilename.c_str());

                    delete FileA;
                    delete FileB;
                    //BMP
                }
                fout << std::endl;
            }
        }
    }
    return 0;

}