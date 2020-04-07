#include "User.h"
#include <iostream>
User::User(Factory f, std::string name, std::string password, int id)
{
	this->ID = id;
	this->username = name;
	this->password = password;
}

User::~User()
{
}

std::string User::GetName()
{
	return this->username;
}

std::string User::GetPassword(User a)
{
	if (a.CheckAdmin() == true) {
		return this->password;
	}
	else {
		 std::cout << "Permission denied" << "\n";
		 return "";
	}
		
}

int User::GetID()
{
	return this->ID;
}

bool User::CheckAdmin()
{
	return this->adminRights;
}

void User::SetName(std::string name)
{
	this->username = name;
}

void User::SetPassword(Admin a, std::string password)
{
	
		this->password = password;
	
}

void User::SetID(int id)
{
	this->ID = id;
}
