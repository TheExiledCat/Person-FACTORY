#include "Factory.h"

Factory::Factory()
{
}

Factory::~Factory()
{
}



User Factory::CreateUser(std::string name, std::string password, Database d)
{
	return User(*this,name,password,d.GetSize());
}
