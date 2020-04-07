#pragma once
#include <string>
#include "Admin.h"
#include "Factory.h"
class User
{
public:
	User(Factory f, std::string name, std::string password, int id);
	~User();
	std::string GetName();
	std::string GetPassword(User a);
	int GetID();
	bool CheckAdmin();
	void SetName(std::string name);
	void SetPassword(Admin a,std::string password);
	void SetID(int id);
private:
	std::string username;
	std::string password;
	int ID;
	bool adminRights;

};

