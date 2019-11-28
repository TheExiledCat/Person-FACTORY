#pragma once
#include <string>
class Factory
{
public:
	Factory();
	~Factory();
	void CreateUser(std::string aName, std::string aPassword);

private:

	std::string username;
	std::string password;
	int userID;

};

