
#include <windows.h> 
#include <stdio.h> 
#include <iostream>

typedef int(__cdecl* MYPROC)(void); //definicja typu wskaznika

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

    return 0;

}