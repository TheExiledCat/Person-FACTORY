#pragma once
#include "User.h"
#include "Database.h"
#include "Factory.h"
#include "Lib.h"
class Admin :public User
{
	
public:
	Admin(std::string name, std::string password);
	~Admin();

	void RequestNewUser( Database *d, Factory* f);
	void ChangeUser(Database* d);
	void RequestNewAdmin( Database *d, Factory *f);
	int GetMenuOptions();
	void RequestUserDeletion(Database* d);
private:
	std::string options[6] = { "Request a new User","Request a new Admin","Change a User","Show User Database","Delete a User","Log Out" };
	
};

