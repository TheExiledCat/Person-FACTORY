#pragma once
#include <string>
#include "Database.h"

int LoginAsAdmin(std::string name, std::string password, Database* d);
int LoginAsUser(std::string name, std::string password, Database* d);
void Hangman(User*u);