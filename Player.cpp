#include <iostream>
#include "Player.hpp"

/*
Default Constructor
no parameters, false Player
*/
Player::Player() {
	id = -1;
	name = "null";
	color = 'n';
	password = "";
}

/*
Constructor for creating a new player
Accepts integer representing player number
*/
Player::Player(int idIn) {
	id = idIn;
	name = "";
	color = ' ';
	password = "";
}

/*
boolean function, checks if user entered password matches
the set Player password
*/
bool Player::checkPassword(std::string stringIn) {
	if (stringIn == password) {
		return 1;
	}
	else {
		return 0;
	}
}

/*
printer functions for testing
*/
void Player::printPlayerInfo() {
	std::cout << "id: " << id << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Color: " << color << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Starting X: " << posX << std::endl;
	std::cout << "Starting Y: " << posY << std::endl;

}
void Player::showHand() {
	std::cout << name << " has a hand of: " << std::endl;

	for (int i = 0; i < static_cast<int>(hand.size()); i++) {
		hand.at(i).displayCard();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Player::viewNotebook() {
	std::string pw;
	int choice;
	std::cout << getName() << ", enter your password: ";
	getline(std::cin, pw);
	if (!checkPassword(pw))
		std::cout << "Wrong password\n";
	else {
		do {
			std::cout << std::endl;
			notebook.display();
			std::cout << "\nWhat would you like to do?\n";
			std::cout << "1. Add an entry\n";
			std::cout << "2. Remove an entry\n";
			std::cout << "3. Clear the notebook\n";
			std::cout << "4. Close the notebook\n";
			cin >> choice;
			useNotebook(choice);
		} while (choice != 4);
	}
}

void Player::useNotebook(int val) {
	std::string entry;
	char ch;
	int idx;
	switch (val) {
	case 1: std::cout << "Enter a new note: ";
		cin.ignore();
		getline(std::cin, entry);
		notebook.addEntry(entry);
		break;
	case 2: std::cout << "Choose an entry number to remove: ";
		cin >> idx;
		notebook.eraseEntry(idx);
		break;
	case 3: std::cout << "Are you sure you want to clear your notes? (y or n): ";
		cin >> ch;
		if (toupper(ch) == 'Y')
			notebook.clear();
		break;
	case 4: std::cout << "Closing notebook...\n" << std::endl;
		break;
	default: std::cout << "Invalid entry\n";
	}
}


/*Accuse Function*/
bool Player::accuse(std::vector<Card> murderCards) {

	std::string guess_person = "";
	std::string guess_weapon = "";
	std::string guess_room = "";

	std::string real_person;
	std::string real_weapon;
	std::string real_room;


	//THIS IS SIMPLY HERE FOR THE TESTING PROCESS SO YOU CAN TEST AN ENDGAME
	/*std::cout << "How did the murder really happen?\n" << std::endl;
	int i = 0;
	for (i = 0; i < murderCards.size(); i++) {
		if (murderCards[i].getType() == 'w') {
			real_weapon = murderCards[i].getName();
		}
		else if (murderCards[i].getType() == 'r') {
			real_room = murderCards[i].getName();
		}
		else if (murderCards[i].getType() == 'c') {
			real_person = murderCards[i].getName();
		}
	}

	std::cout << "WHO: " << real_person << "\n" << std::endl;
	std::cout << "WHAT: " << real_weapon << "\n" << std::endl;
	std::cout << "WHERE: " << real_room << "\n" << std::endl;*/

	std::cout << "Please enter WHO you think did it.\n" << std::endl;
	getline(std::cin, guess_person);
	std::cout << "Please enter WHAT weapon you think they used.\n" << std::endl;
	getline(std::cin, guess_weapon);
	std::cout << "Please enter WHERE you think it happened.\n" << std::endl;
	getline(std::cin, guess_room);

	std::cout << "How did the murder really happen?\n" << std::endl;
	int i = 0;
	for (i = 0; i < murderCards.size(); i++) {
		if (murderCards[i].getType() == 'w') {
			real_weapon = murderCards[i].getName();
		}
		else if (murderCards[i].getType() == 'r') {
			real_room = murderCards[i].getName();
		}
		else if (murderCards[i].getType() == 'c') {
			real_person = murderCards[i].getName();
		}
	}

	std::cout << "WHO: " << real_person << "\n" << std::endl;
	std::cout << "WHAT: " << real_weapon << "\n" << std::endl;
	std::cout << "WHERE: " << real_room << "\n" << std::endl;

	if ((guess_person == real_person) && (guess_weapon == real_weapon) && (guess_room == real_room)) {
		std::cout << "You have won the game, CONGRATS!\n" << std::endl;
		return true;
	}
	else {
		std::cout << "Unfortunately, you have lost this game, as you only get one accusation!\n" << std::endl;
		return false;
	}

}



/*
Accessor functions for getting private members
*/
int Player::getId() {
	return id;
}
std::string Player::getName() {
	return name;
}
char Player::getColor() {
	return color;
}

int Player::getPositionX() {
	return posX;
}
int Player::getPositionY() {
	return posY;
}

/*
Mutator functions for setting private members
*/
void Player::setColor(char colorIn) {
	color = colorIn;
}
void Player::setName(std::string nameIn) {
	name = nameIn;
}
void Player::setPassword(std::string passwordIn) {
	password = passwordIn;
}


void Player::setPositionX(int posX1) {
	posX = posX1;
}

void Player::setPositionY(int posY1) {
	posY = posY1;
}

void Player::setStartingPosition(int pos) {
	if (pos == 1) {
		posX = 3;
		posY = 0;
	}
	else if (pos == 2) {
		posX = 4;
		posY = 3;
	}
	else if (pos == 3) {
		posX = 3;
		posY = 6;
	}
	else if (pos == 4) {
		posX = 0;
		posY = 5;
	}
	else if (pos == 5) {
		posX = 0;
		posY = 2;
	}
	else if (pos == 6) {
		posX = 1;
		posY = 0;
	}
}