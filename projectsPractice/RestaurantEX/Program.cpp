#include "LoginForm.h"
#include "MainForm.h"
#include "RegisterForm.h"

using namespace System;
using namespace System::Windows::Forms;

//int main(int argc, char* argv[])
void main(array<String^>^ args) 
{
	/*NativeObject* n = new NativeObject();
	ManagedObject^ m = gcnew ManagedObject();*/

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	

	User^ user = nullptr;
	while (true) 
	{
		RestaurantEX::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.switchToRegister)
		{
			//show the register form
			RestaurantEX::RegisterForm registerForm;
			registerForm.ShowDialog();

			if (registerForm.switchToLogin)
			{
				continue;
			}
			else 
			{
				user = registerForm.user;
				break;
			}
		}
		else
		{
			user = loginForm.user;
			break;
		}
	}
	/*RestaurantEX::LoginForm loginForm;
	loginForm.ShowDialog();
	User^ user = loginForm.user;*/

	if (user != nullptr)
	{
		//MessageBox::Show("Successfull Authentication of " + user->name, "Program.cpp", MessageBoxButtons::OK);
		RestaurantEX::MainForm mainForm(user);
		Application::Run(% mainForm);
	}
	else
	{
		MessageBox::Show("Authentication Cancelled", "Program.cpp", MessageBoxButtons::OK);
	}
}