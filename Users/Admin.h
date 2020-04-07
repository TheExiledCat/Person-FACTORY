#pragma once
#include "User.h"
class Admin : public User{
public:
	Admin(std::string name,std::string password,int id);
	~Admin();

	void PromoteUser(User u);
private:

}