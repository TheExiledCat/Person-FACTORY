#pragma once
#include <string>
#include <iostream>

class User
{
public:
	User(std::string name, std::string password);
	~User();
	std::string GetName();
	std::string GetPassword(User a);
	int GetID();
	bool CheckAdmin();
	void SetName(std::string name);
	void SetPassword(std::string password);
	void SetID(int id);
	
protected:
	std::string username;
	std::string password;
	int ID;
	bool adminRights=false;

};

