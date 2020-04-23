#include "Menu.hpp"


/*
Default constructor, will generate 4 player objects and add them into the
member variable vector
*/
Menu::Menu() {

}

/*
Set up the 4 players/users
Each player will get a name, random color, player id, and password

FUTURE: each player will get a hand of Card objects
*/
std::vector<Player> Menu::setup() {

}


/*
Generate a random char representing a color
Returns a char
*/
char Menu::generate_color() {
	srand(time(NULL));
	const char colorArray[6] = { 'r', 'b', 'g', 'y', 'v', 'w' };
	int randIndex = rand() % 6;
	char choice = colorArray[randIndex];
	return choice;
}