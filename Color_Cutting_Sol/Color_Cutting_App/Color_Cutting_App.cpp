
#include <windows.h> 
#include <stdio.h> 
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef int(__cdecl* MYPROC)(void); //definicja typu wskaznika
typedef unsigned char byte;


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



            // extract image height and width from header
            memcpy(&width, data + 18, sizeof(int));
            memcpy(&height, data + 22, sizeof(int));

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
            std::cout << ProcAdd();
        }
        // Free the DLL module.
        fFreeResult = FreeLibrary(hinstLib); //na koniec programu, zwalnia wskaznik na biblioteke a zarazem wszystko z nia zwiazane
    }


    //fragment z cpp

    HINSTANCE hinstLibC; //obiekt przechowujacy biblioteke z ktorej przechwycimy procedure
    MYPROC ProcAddC; //typ wskaznika na funkcje z argumentami wyzej
    BOOL fFreeResultC, fRunTimeLinkSuccessC = FALSE;

    // Get a handle to the DLL module.

    hinstLibC = LoadLibrary(TEXT("Dll_CPP.dll")); //zaladowanie biblioteki do obiektu

    // If the handle is valid, try to get the function address.

    if (hinstLibC != NULL) //sprawdzamy czy biblioteka sie zaladowala
    {
        ProcAddC = (MYPROC)GetProcAddress(hinstLibC, "FProc"); //zaladowanie funkcji FProc z biblioteki do wskaznika
        // If the function address is valid, call the function.
        if (NULL != ProcAddC) //sprawdzamy czy funkcja sie zaladowala dobrze
        {
            fRunTimeLinkSuccessC = TRUE;
            std::cout << ProcAddC();
        }
        // Free the DLL module.
        fFreeResultC = FreeLibrary(hinstLibC); //na koniec programu, zwalnia wskaznik na biblioteke a zarazem wszystko z nia zwiazane
    }


    // If unable to call the DLL function, use an alternative.
    if (!fRunTimeLinkSuccess)
        printf("Message printed from executable\n");
    if (!fRunTimeLinkSuccessC)
        printf("C Message printed from executable\n");

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