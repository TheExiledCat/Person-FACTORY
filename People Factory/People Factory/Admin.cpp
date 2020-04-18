#include "Admin.h"

Admin:: Admin(std::string name,std::string password)
	:User{name,password}
{
	
}

Admin::~Admin()
{
}

void Admin::RequestNewUser(std::string name, std::string password, Database d, Factory f)
{
	f.CreateUser(name, password, d);
}

void Admin::ChangeUser(int ID, std::string newName, std::string newPassword,Database d)
{
	std::string oldName=d.GetUser(ID).GetName();
	
	d.GetUser(ID).SetName(newName);
	d.GetUser(ID).SetPassword(newPassword);
	std::cout << "Set user with name |" << oldName << "|'s information to:\n " << "Name: " << newName << "\n" << "Password: " << newPassword << "\n";

}

void Admin::RequestNewAdmin(std::string name, std::string password, Database b, Factory f)
{
}

int Admin::GetMenuOptions()
{
	
	std::cout << "Options:\n"<<"\n";
	
	for (int i = 0; i<std::size(this->options); i++) {
		
		
			std::cout << i+1 << ". " << this->options[i]<<"\n";
	}
	std::cout << "\nChoose the number of the option you want to fulfill\n"<<"\n";
	std::string input;
	std::cin >> input;
	int choice;
	try {
		choice = std::stoi(input);
		if (choice > 0 && choice < std::size(this->options)) {
			return choice;
		}
		else return -1;
	}
	catch(std::invalid_argument const& e){
		std::cout << "Not a valid choice";
		return  -1;
		
	}
}


