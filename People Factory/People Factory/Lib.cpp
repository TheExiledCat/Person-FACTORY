#include "Lib.h"


int LoginAsAdmin(std::string name, std::string password, Database* d) {

	if (d->ContainsUser(name, password, true)) {

		return 0;
	}
	else {
		std::cout << "Failure logging in, username might be wrong.\n\n";
		return -1;
	}
}

int LoginAsUser(std::string name, std::string password, Database* d)
{
	if (d->ContainsUser(name, password, false)) {

		return 1;
	}
	else {
		std::cout << "Failure logging in, username might be wrong.\n\n";
		return -1;
	}
	
}
void Hangman(User * u) {//game
	std::vector<std::string> words{
		"SCHOOL",
		"WORK",
		"CORONA",
		"ONLINE",
		"GAME"
	};
	bool game = true;
	int lives = 10;
	std::vector<char> misses;
	
	std::cout << "Welcome to hangman! " << u->GetName() << "!\n\n";
	while (game) {

	}
}