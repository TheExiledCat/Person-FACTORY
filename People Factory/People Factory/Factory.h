#pragma once
#include "User.h"
#include "Database.h"
class Factory
{
public:
	Factory();
	~Factory();
	User CreateUser(std::string name,std::string password,Database d);
	
private:

};

