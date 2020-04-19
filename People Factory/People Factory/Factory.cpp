#include "Factory.h"
#include "Admin.h"
Factory::Factory()
{
}

Factory::~Factory()
{
}



User Factory::CreateUser(std::string name, std::string password, Database* d,bool admin)
{
	User* newUser;
	if (!admin) {
		
		
		newUser = new User(name, password);
		
	}
	else {
		newUser = new Admin(name, password);
	}
	
	d->AddUser(newUser);
	return *newUser;
}
