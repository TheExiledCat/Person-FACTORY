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
	void Show(User *a);
	void DeleteUser(int id);
	bool ContainsUser(std::string name,bool admin);
	User* GetUserByAccount(std::string name, std::string password,  bool admin);
private:
	std::vector<User> users;
};



