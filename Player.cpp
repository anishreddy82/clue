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
}
void Player::showHand() {
	std::cout << name << " has a hand of: " << std::endl;

	for (int i = 0; i < static_cast<int>(hand.size()); i++) {
		hand.at(i).displayCard();
		std::cout << std::endl;
	}
	std::cout << std::endl;
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