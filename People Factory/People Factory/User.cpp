#include "User.h"
#include <iostream>


User::User(std::string name, std::string password)
{
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

std::string User::GetPassword()
{
		return this->password;
	
	
		
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

void User::SetPassword( std::string password)
{
	
		this->password = password;
	
}

void User::SetID(int id)
{
	this->ID = id;
}
