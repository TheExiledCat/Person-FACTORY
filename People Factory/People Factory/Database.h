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
private:
	std::vector<User> users;
};



