// People Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Admin.h"
#include "Factory.h"
#include "Database.h"
int main()
{
	Database* currentDatabase = new Database();
	Factory* currentFactory = new Factory();
	std::cout << "Hello new admin, fill in your name for initialization\n";
	std::string name;
	std::string password;
	std::cout << "Name:\n";

	std::cin >> name;
	std::cout << "Password:\n";
	std::cin >> password;
	Admin* Director = new Admin(name, password);
	std::cout << "Welcome to the User Factory," << Director->GetName() << "\n";
	std::string input;
	while (true) {
	start:
		int i=Director->GetMenuOptions();
		switch (i) {
		default: {
				goto start;
				break;
		}
		case 1: {
			std::string name;
			std::string password;
			std::cout << "Creating new User\n" << "\n";
			std::cout << "Insert name:\n";
			std::cin >> name;
			std::cout << "Insert password:\n";
			std::cin >> password;
			Director->RequestNewUser(name, password, *currentDatabase, *currentFactory);
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		}
	}
	
	return 0;
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
