#include "pch.h"
#include "Form1.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Form1.h"

[STAThread]
int main()
{
	Windows::Forms::Application::EnableVisualStyles();
	Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	Windows::Forms::Application::Run(gcnew CppCLRWinFormsProject::Form1());
	return 0;
}