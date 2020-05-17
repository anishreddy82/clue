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
	int posX;
	int posY;


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
	int getPositionX();
	int getPositionY();
	void setName(std::string nameIn);
	void setColor(char colorIn);
	void setStartingPosition();
	void setPassword(std::string passwordIn);
	void setPositionX(int posX1);
	void setPositionY(int posY1);
	bool checkPassword(std::string stringIn);
	void printPlayerInfo();
};
