#pragma once
#include <vector>

#include "User.h"
class Database
{
public:
	Database();
	User* GetUser(int id);
	void AddUser(User* u);
	int GetSize();
	void Show();
	void DeleteUser(int id);
	bool ContainsUser(std::string name,std::string password,bool admin);
	User* GetUserByAccount(std::string name, std::string password);

private:
	std::vector<User> users;
};



