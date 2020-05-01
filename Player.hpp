#pragma once
#include <string>
#include <vector>
#include "Card.hpp"
#include "Notebook.hpp"
class Player
{
private:
	int id;
	std::string name;
	char color;
	std::string password;
	Notebook notebook;

public:
	Player();
	Player(int idIn);
	std::vector<Card> hand;
	
	std::string getName();
	void showHand();
	void viewNotebook();
	void useNotebook(int);
	int getId();
	char getColor();
	void setName(std::string nameIn);
	void setColor(char colorIn);
	void setPassword(std::string passwordIn);
	bool checkPassword(std::string stringIn);
	void printPlayerInfo();
};
