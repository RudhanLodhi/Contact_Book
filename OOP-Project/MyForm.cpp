#include "Login.h"
#include "Address.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	OOP_Project::MyForm Login;
	Application::Run(%Login);
}
