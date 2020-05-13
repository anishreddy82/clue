#include <iostream>
#include <string>
#include "Menu.hpp"


/*
Default constructor, will generate 4 player objects and add them into the
member variable vector
*/
Menu::Menu() {
	colors = { 'r', 'b', 'g', 'y', 'v', 'w' };
	positions = {1, 2, 3, 4, 5, 6};
}

/*
Set up the x players/users
Each player will get a name, random color, player id, and password
Passwords are optional
FUTURE: each player will get a hand of Card objects
*/
std::vector<Player> Menu::setup(int x) {
	
	for (int i = 1; i <= x; i++) {
		std::cout << "_______________________________________________________________" << std::endl;
		Player new_player = Player(i);

		setupPlayerName(new_player);
		setupPlayerColor(new_player);
		setupPlayerPassword(new_player);

		players.push_back(new_player);
	}
	return players;
}

void Menu::setupPlayerName(Player &current_player) {
	std::cout << "Player " << current_player.getId() << ". Please enter your name: ";
	std::string nameIn;
	std::getline(std::cin, nameIn);
	current_player.setName(nameIn);
	std::cout << std::endl;
}

void Menu::setupPlayerColor(Player &current_player) {
	current_player.setColor(generate_color());
	current_player.setStartingPosition(generate_randPos());
}

void Menu::setupPlayerPassword(Player &current_player) {
	std::cout << "(Optional) Please enter your password to secure your turn: ";
	std::string passwordIn;
	std::getline(std::cin, passwordIn);
	current_player.setPassword(passwordIn);
}

char Menu::generate_color() {
	srand(time(NULL));
	int randIndex = rand() % static_cast<int>(colors.size());
	char choice = colors.at(randIndex);
	colors.erase(colors.begin() + randIndex);
	return choice;
}

int Menu::generate_randPos(){
	srand(time(NULL));
	int randNum = rand() % positions.size();
	int choice = positions.at(randNum);
	positions.erase(positions.begin() + randNum);
	return choice;
}



