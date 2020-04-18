#include "Factory.h"

Factory::Factory()
{
}

Factory::~Factory()
{
}



User Factory::CreateUser(std::string name, std::string password, Database d)
{
	
	User newUser =  User( name,password) ;
	d.AddUser(newUser);
	
	return newUser;
}
