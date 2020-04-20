// People Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lib.h"
#include "Admin.h"
#include "Factory.h"
#include "Database.h"
int main()
{
#pragma region Initialization


	User* currentUser;
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
	
	std::getline(std::cin , name);
	std::cout << "Password:\n";
	std::getline(std::cin , password);
	Admin* Director = new Admin(name, password);
	std::cout << "Welcome to the User Factory," << Director->GetName() << "\n" << "Logging in\n\n";
	currentDatabase->AddUser(Director);
#pragma endregion
	while (true) {//enter loop
		
		loop:
		switch (lS) {
		case ADMIN: {//lets you make more users and admins
		start:
			if (Director != NULL) {
				int i = Director->GetMenuOptions();
				switch (i) {
				default: {
					std::cout << "Not a valid Option\n\n";

					break;
				}
				case 1: {


					Director->RequestNewUser(currentDatabase, currentFactory);
					break;
				}
				case 2: {


					Director->RequestNewAdmin(currentDatabase, currentFactory);
					break;
				}
				case 3: {
					Director->ChangeUser(currentDatabase);
					break;
				}
				case 4: {
					currentDatabase->Show();
					break;
				}
				case 5: {
					Director->RequestUserDeletion(currentDatabase);
					break;
				}
				case 6: {
					lS = LOGGED_OUT;
					std::cout << "Logging out\n\n";
					goto loop;
				}
			}
			
			}
			
			break;
		}
		case USER: {//gives u the mini game
			Hangman(currentUser);
			lS = LOGGED_OUT;
			break;
		}
		case LOGGED_OUT: {//Shows you the logiin screen
			std:: cout<<"Choose Option you want to make:\n\n";
			std::cout << "1. Open person factory with admin account\n";
			std::cout << "2. Open minigame as user\n";
			std::cout << "3. Exit program\n";
			std::string input;
			std::cin >> input;
			try {

				int choice = std::stoi(input);
				switch (choice) {
				default: {
					std::cout << "Not a valid choice\n\n";
					break;
				}
				case 1: {
					std::cout << "Enter Username:\n";
					std::cin.ignore();
					std::string name;
					std::string password;
					std::getline(std::cin, name);
					std::cout << "Enter Password:\n";
					std::getline(std::cin, password);
					if (LoginAsAdmin(name, password, currentDatabase) == 0) {
						lS = ADMIN;
						
					}
					else {
						lS = LOGGED_OUT;
					}
					break;


				}
				case 2: {
					std::cout << "Enter Username:\n";
					std::cin.ignore();
					std::string name;
					std::string password;
					std::getline(std::cin, name);
					std::cout << "Enter Password:\n";
					std::getline(std::cin, password);
					if (LoginAsUser(name, password, currentDatabase) == 0&&currentDatabase->GetUserByAccount(name,password)!=NULL) {
						lS = USER;
						currentUser = currentDatabase->GetUserByAccount(name, password);
					}
					else {
						lS = LOGGED_OUT;
						
					}
					
					break;
				}
				case 3: {
					exit(0);
				}
				}
			}
			catch (std::invalid_argument const& e) {
				std::cout << "Not a valid option\n";

				
			}

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
