#pragma once
#include <string>
#include "Admin.h"
class User
{
public:
	User(std::string name,std::string password);                  
	~User();
	std::string GetName(Admin a);

	void SetName(std::string name,Admin a);
	void SetID(int id,Admin a);
	int GetID(Admin a);
	bool CheckAdmin(User u);
private:
	std::string username;
	std::string password;
	int userID;



};

