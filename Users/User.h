#pragma once
#include <string>
class User
{
public:
	User();
	~User();
	std::string GetName() {

		return username;

	}

	void SetName(std::string name) {
		username = name;
	}
	void SetID(int id) {
		userID = id
	}

private:
	std::string username;
	std::string password;
	int userID;



};

