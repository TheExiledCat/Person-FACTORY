#include "Admin.h"
#include "Lib.h"
Admin:: Admin(std::string name,std::string password)
	:User{name,password}
{
	this->adminRights = true;
}

Admin::~Admin()
{
}

void Admin::RequestNewUser( Database *d, Factory *f)
{
	std::string name;
	std::string password;
	std::cout << "Creating new User\n" << "\n";
	std::cout << "Insert name:\n";
	std::cin.ignore();
	std::getline(std::cin, name);
	

	std::cout << "Insert password:\n";
	std::getline(std::cin, password);

	User u =f->CreateUser(name, password, d,false);
	std::cout << "Created User: " << u.GetName() << ".\n\n";
}

void Admin::ChangeUser(Database *d)
{
	std::string newName;
	std::string newPassword;
	int id;
	std::string input;
	std::cin.ignore();
	std::cout << "Which user do you want to change by ID?\n";
	std::getline(std::cin, input);
	
	id = std::stoi(input, nullptr);
	std::string oldName=d->GetUser(id)->GetName();
	std::cout << "What should the users name be changed to?\n";

	std::getline(std::cin, newName);
	std::cout << "What should the users password be changed to?\n";
	std::getline(std::cin, newPassword);
	d->GetUser(id)->SetName(newName);
	d->GetUser(id)->SetPassword(newPassword);
	std::cout << "Set user with name |" << oldName << "| and ID |"<<d->GetUser(id)->GetID()<<"| information to:\n" << "Name: " << d->GetUser(id)->GetName() << "\n" << "Password: " << newPassword << "\n";

}

void Admin::RequestNewAdmin( Database* d, Factory * f)
{
	std::string name;
	std::string password;
	std::cout << "Creating new Admin" << "\n";
	std::cout << "Insert name:\n";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Insert password:\n";
	std::getline(std::cin, password);

	User* u = &f->CreateUser(name, password, d, true);
	std::cout << "Created Admin: " << u->GetName() << ".\n\n";
}

int Admin::GetMenuOptions()
{
	
	std::cout << "\nOptions:\n"<<"\n";
	
	for (int i = 0; i<std::size(this->options); i++) {
		
		
			std::cout << i+1 << ". " << this->options[i]<<"\n";
	}
	std::cout << "\nChoose the number of the option you want to fulfill\n"<<"\n";
	std::string input;
	std::cin >> input;
	int choice;
	try {
		choice = std::stoi(input);
		if (choice > 0 && choice <= std::size(this->options)) {
			return choice;
		}
		else return -1;
	}
	catch(std::invalid_argument const& e){
		std::cout << "Not a valid choice\n";
		return  -1;
		
	}
}

void Admin::RequestUserDeletion(Database* d)
{
	std::cout << "What is the ID of the user you want to delete?:\n";
	std::cin.ignore();
	std::string input;
	std::getline(std::cin, input);
	int choice;
	try {
		choice = std::stoi(input);
		if (choice >= 0 && choice < d->GetSize()) {
		Confirm:
			std::cout << "Are you sure you want to delete User " << d->GetUser(choice)->GetName() << "? y/n";
			std::cin >> input;
			if (input == "y") {
				User* u = d->GetUser(choice);
				d->DeleteUser(choice);
				std::cout << "Deleted User at index " << u->GetID();
				return;

			}
			else if (input == "n") {
				return;
			}
			else {
				goto Confirm;
			}
		}
		
	}
	catch (std::invalid_argument const& e) {
		std::cout << "No User with that ID\n";
		
		return;
	}
	
	
}





