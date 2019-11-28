#pragma once
#include "User.h"
#include "Factory.h"
class Admin:User
{
public:
	Admin();
	~Admin();
	void ChangeUser(User user, std::string aName, std::string aPassword, int id);
	void RequestUser(std::string aName, std::string aPassword, Database aDatabase, Factory afactory);

private: 
	bool hasKey;

};

