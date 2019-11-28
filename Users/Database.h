#pragma once
#include "Admin.h"
class Database
{
public:
	Database();
	~Database();
	User users[];

	User GetUser();
	void AddUser(User aUser, Admin aAdmin);
private:
};

