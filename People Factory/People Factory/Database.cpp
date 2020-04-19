#include "Database.h"

#include <iomanip>
Database::Database()
{
}

User *Database::GetUser(int id)
{
	return &users[id];
}

void Database::AddUser(User* u)
{
	u->SetID(users.size());
	
	users.push_back(*u);
	
}

int Database::GetSize()
{
	return users.size();
}

void Database::Show(User* a)
{
	std::cout << "\nThese Users exist in database:\n\n";
	std::cout <<"ID"<<std::setw(10) <<"Name" << std::setw(30) << "Password" << std::setw(10) << "Admin\n\n";
std::string  admin;
	for (int i = 0; i < users.size(); i++) {
		admin = users[i].CheckAdmin() ? "Yes" : "No";
		std::cout <<users[i].GetID() << " " << users[i].GetName() << std::setw(34 - users[i].GetName().length()) << users[i].GetPassword(*a)<<std::setw(10) << admin << "\n";
	}
	std::cout << "\n";
}




