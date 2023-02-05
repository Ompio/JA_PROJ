#include "pch.h"
#include "BMP.h"

typedef void(__stdcall* Blur)(BYTE*, int, int, int, int);

void readBMP(BMP* bmp, const char* filename)
{
	std::ifstream inputFile(filename, std::ios::in | std::ios::binary | std::ios::ate);
	bmp->picture_size = inputFile.tellg();
	inputFile.seekg(0, std::ios::beg);
	bmp->data = new char[bmp->picture_size];
	inputFile.read(bmp->data, bmp->picture_size);
	bmp->file_header = reinterpret_cast<PBITMAPFILEHEADER>(bmp->data);
	bmp->info_header = reinterpret_cast<PBITMAPINFOHEADER>(bmp->data + sizeof(BITMAPFILEHEADER));
	bmp->pixels = reinterpret_cast<BYTE*>(bmp->data + bmp->file_header->bfOffBits);
	inputFile.close();
}

void saveBMP(BMP* bmp, const char* filename)
{
	std::ofstream outputFile(filename, std::ios::out | std::ios::binary);
	outputFile.write(bmp->data, bmp->picture_size);
	outputFile.close();
}
bool checkFile(const char* file_name)
{
	std::string extension = "";
	bool dotAppeared = false;
	for (int i = 0; i < strlen(file_name); i++) {
		if (file_name[i] == '.')
			dotAppeared = true;
		if (dotAppeared == true)
			extension += file_name[i];
	}
	if (extension == ".bmp")
		return true;
	else
		return false;
}
long long run(const char* ifile_name, const char* ofile_name, const int numberofThreads, bool dllType)
{

	BMP* bmp = new  BMP;
	readBMP(bmp, ifile_name);
	HINSTANCE lib = loadLibrary(dllType);
	long long time = 0;
	time += Blur_run(lib, bmp, numberofThreads);
	saveBMP(bmp, ofile_name);
	delete bmp;
	//System::Windows::Forms::MessageBox::Show("Ukończono rozmycie obrazu", "Koniec", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
	return time;
}
long long Blur_run(HINSTANCE library, BMP* bmp, short threadNumber)
{
	Blur blur = (Blur)GetProcAddress(library, "Blur");
	int divideParts = bmp->info_header->biHeight / threadNumber;
	std::thread* thread = new std::thread[threadNumber];
	for (int i = 0; i < threadNumber - 1; i++)
		thread[i] = std::thread(blur, bmp->pixels, bmp->picture_size, bmp->info_header->biWidth, i * divideParts, (i + 1) * divideParts);

	thread[threadNumber - 1] = std::thread(blur, bmp->pixels, bmp->picture_size, bmp->info_header->biWidth, (threadNumber - 1) * divideParts, bmp->info_header->biHeight - 1);

	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();

	for (short i = 0; i < threadNumber; i++)
	{
		thread[i].join();
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	//std::cout << "Time Blur: " << time << "ms" << std::endl;
	delete[] thread;
	return time;
}

HINSTANCE loadLibrary(bool typeCpp) {
	HINSTANCE library;
	if (typeCpp)
		library = LoadLibraryA("DllCpp.dll");
	else
		library = LoadLibraryA("DllAsm.dll");

	return library;
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