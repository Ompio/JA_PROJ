#include "pch.h"
#include "ImageF.h"

typedef void(__cdecl* MYPROC)(BYTE*, BYTE*, BYTE*); //definicja typu wskaznika

BMPFile::BMPFile(const char* fileName)
{
    this->fileName = fileName;

    std::fstream file(fileName, std::fstream::in | std::fstream::binary);

    if (file) {

        file.seekg(0, file.end);
        dataSize = file.tellg();
        file.seekg(0, file.beg);

        data = new BYTE[dataSize];
        file.read((char*)data, dataSize);

        fileHeader = PBITMAPFILEHEADER(data);
        infoHeader = PBITMAPINFOHEADER(data + sizeof(BITMAPFILEHEADER));
        pixels = data + fileHeader->bfOffBits;
    }

    file.close();
}
BMPFile::BMPFile(const BMPFile& file)
{
    this->fileName = file.fileName;
    this->dataSize = file.dataSize;
    this->data = new BYTE[dataSize];
    std::copy(file.data, file.data + file.dataSize, this->data);

    fileHeader = PBITMAPFILEHEADER(data);
    infoHeader = PBITMAPINFOHEADER(data + sizeof(BITMAPFILEHEADER));
    this->pixels = data + fileHeader->bfOffBits;
}
BMPFile::~BMPFile()
{
    delete[] data;
}
void BMPFile::saveFile() {
    saveFile(this->fileName);
}
void BMPFile::saveFile(const char* _fileName)
{
    std::fstream file(_fileName, std::fstream::out | std::fstream::binary);
    if (file) {
        file.write((char*)this->data, dataSize);
    }
    file.close();
}

long long run(const char* ifile_name, const char* ofile_name, const int numberofThreads, bool dllType, BYTE colors[])
{

    std::chrono::microseconds durationT;

    HINSTANCE hinstLib; //obiekt przechowujacy biblioteke z ktorej przechwycimy procedure
    MYPROC ProcAdd; //typ wskaznika na funkcje z argumentami wyzej
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
    bool useCpp;
    if (dllType) {
        useCpp = true;
    }
    else useCpp = false;
    BMPFile* FileA;
    BMPFile* FileB;
    FileA = new BMPFile(ifile_name);  // BMPFile* FileB("c.bmp");
    FileB = new BMPFile(*FileA);
    std::cout << "dupa";
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
            int threadNumber = numberofThreads;
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
            byte colorToSeek[3] = { 79          //Wartoœæ B
                                    ,13        //Wartoœæ G
                                    ,248 };     //Wartoœæ R

            //std::cout << (int)colorToSeek[0] << " " << (int)(colorToSeek[1]) << " " << (int)(colorToSeek[2]) << std::endl;

            byte colorChanged[3] = { 128       //Wartoœæ B
                                        ,255       //Wartoœæ G
                                        ,128 };    //Wartoœæ R

            colorToSeek[0] = colors[0];          //Wartoœæ B
            colorToSeek[1] = colors[1];        //Wartoœæ G
            colorToSeek[2] = colors[2];     //Wartoœæ R

            colorChanged[0] = colors[3];//Wartoœæ B
            colorChanged[1] = colors[4];//Wartoœæ G
            colorChanged[2] = colors[5];//Wartoœæ R

            int threadOffset = alliterations / threadNumber; //mo¿e sprawiaæ problemy gdy iloœæ threadów i ilosc iteracji bêdzie siê nie zgadzaæ
            int lastPixels = alliterations % threadNumber;

            auto f = [&ProcAdd, &PixelB, &colorToSeek, &colorChanged](int threadNumber, int offset, int  add = 0)
            {
                for (int i = 0 + offset * threadNumber; i < offset * (threadNumber + 1) - 1 + add; i += 4) {
                    ProcAdd(PixelB + i * 3, colorToSeek, colorChanged);
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

            durationT = std::chrono::duration_cast<std::chrono::microseconds>(stopT - startT);
            //std::cout << "time elapsed: " << durationT.count() << std::endl;
            
        }
        fFreeResult = FreeLibrary(hinstLib); //na koniec programu, 
        //zwalnia wskaznik na biblioteke a zarazem wszystko z nia zwiazane
    }

    if (!fRunTimeLinkSuccess)
        printf("Message printed from executable\n");

    FileB->saveFile(ofile_name);

    delete FileA;
    delete FileB;
    
    return durationT.count();
}

void MarshalString(System::String^ s, std::string& os) {
    const char* chars =
        static_cast<const char*>((System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer());
    os = chars;
    System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

void MarshalString(System::String^ s, std::wstring& os) {
    const wchar_t* chars =
        static_cast<const wchar_t*>((System::Runtime::InteropServices::Marshal::StringToHGlobalUni(s)).ToPointer());
    os = chars;
    System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}