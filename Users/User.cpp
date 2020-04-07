#include "pch.h"
#include "User.h"


User::User(std::string name, std::string password)
{
	this.username = name;
	this->password = password;
}

User::~User()
{
}

std::string User::GetName(Admin a)
{
	return std::string();
}



void User::SetName(std::string name, Admin a)
{
}

void User::SetID(int id, Admin a)
{
}

int User::GetID(Admin a)
{
	return this->userID
}

bool User::CheckAdmin(User u)
{
	Admin a;
	if (typeid(u) == typeid(a) {
		return true;
	}
	return false;
}






