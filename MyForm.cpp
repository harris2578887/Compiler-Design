#include <Windows.h>
#include "Source.h"
#include "MyForm.h"

#include <msclr/marshal.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CompilerC::MyForm form;
	Application::Run(% form);
	return 0;
}