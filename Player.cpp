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
	switch(val) {
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
		case 4: std::cout << "Closing notebook...\n";
			break;
		default: std::cout << "Invalid entry\n";
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

int Player::getPositionX(){
	return posX;
}
int Player::getPositionY(){
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

void Player::setStartingPosition(int pos){
	if(pos == 1){
		posX = 0;
		posY = 3;
	}
	else if(pos == 2){
		posX = 3;
		posY = 4;
	}
	else if(pos == 3){
		posX = 6;
		posY = 3;
	}
	else if(pos == 4){
		posX = 5;
		posY = 0;
	}
	else if(pos == 5){
		posX = 2;
		posY = 0;
	}
	else if(pos == 6){
		posX = 0;
		posY = 1;
	}
}

void Player::setStartingPosition() {
	if (color == 'r') {
		posX = 8;
		posY = 0;
	}
	else if (color == 'b') {
		posX = 0;
		posY = 9;
	}
	else if (color == 'g') {
		posX = 4;
		posY = 11;
	}
	else if (color == 'y') {
		posX = 11;
		posY = 3;
	}
	else if (color == 'w') {
		posX = 7;
		posY = 11;
	}
	else {
		posX = 0;
		posY = 2;
	}
}
