#pragma once
#include "User.h"
#include "Database.h"
#include "Factory.h"

class Admin :public User
{
	
public:
	Admin(std::string name, std::string password);
	~Admin();

	void RequestNewUser(std::string name, std::string password, Database d, Factory f);
	void ChangeUser(int ID, std::string newName, std::string newPassword,Database d);
	void RequestNewAdmin(std::string name, std::string password, Database b, Factory f);
	int GetMenuOptions();
	
private:
	std::string options[4] = { "Request a new User","Request a new Admin","Change a User","Show User Database" };
};

