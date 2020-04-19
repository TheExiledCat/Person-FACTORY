// People Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Admin.h"
#include "Factory.h"
#include "Database.h"
int main()
{
#pragma region Initialization



	Database* currentDatabase = new Database();
	Factory* currentFactory = new Factory();
	enum  loginState {
		ADMIN,
		USER,
		LOGGED_OUT
	};
	loginState lS;
	lS = ADMIN;
	std::cout << "Hello new admin, fill in your name for initialization\n";
	std::string name;
	std::string password;
	std::cout << "Name:\n";

	std::cin >> name;
	std::cout << "Password:\n";
	std::cin >> password;
	Admin* Director = new Admin(name, password);

	std::cout << "Welcome to the User Factory," << Director->GetName() << "\n" << "Logging in";
	std::string input;
#pragma endregion
	while (true) {//enter loop
		switch (lS) {
		case ADMIN: {
		start:
			int i = Director->GetMenuOptions();
			switch (i) {
			default: {
				std::cout << "Not a valid Option\n\n";
				goto start;
				break;
			}
			case 1: {


				Director->RequestNewUser(currentDatabase, currentFactory);
				goto start;
			}
			case 2: {


				Director->RequestNewAdmin(currentDatabase, currentFactory);
				goto start;
			}
			case 3: {
				Director->ChangeUser(currentDatabase);
				goto start;
			}
			case 4: {
				currentDatabase->Show(Director);
				goto start;
			}

			}
			break;
		}
		case USER: {

		}
		}
		return 0;
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
