#pragma once
#include <vector>
#include "User.h"
class Database
{
public:
	User GetUser(int id);
	void AddUser(User u);
	int GetSize();
private:
	std::vector<User> users;
};

