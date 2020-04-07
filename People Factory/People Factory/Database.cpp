#include "Database.h"

User Database::GetUser(int id)
{
	return users[id];
}

void Database::AddUser(User u)
{
	u.SetID(users.size);
	users.push_back(u);
}

int Database::GetSize()
{
	return users.size;
}
