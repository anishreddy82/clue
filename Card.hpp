#pragma once

#include <string>

class Card {
private:
	std::string name;
	char type;
	bool murder;

public:
	Card();
	Card(std::string nameIn, char typeIn);
	void displayCard();
	char getType();
	std::string getName();
	void setMurder();
	bool isMurder();
};