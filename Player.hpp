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
	int accuseInt;
	bool winner;

public:

	Player();
	Player(int idIn);
	std::vector<Card> hand;
	std::string getName();
	void showHand();
	void viewNotebook();
	void useNotebook(int);

	bool accuse(std::vector<Card>);

	void changeAccuse();
	int getAccuse();
	int getId();
	char getColor();
	int getPositionX();
	int getPositionY();
	void setName(std::string nameIn);
	void setColor(char colorIn);
	void setStartingPosition(int pos);
	void setPassword(std::string passwordIn);
	void setPositionX(int posX1);
	void setPositionY(int posY1);
	bool checkPassword(std::string stringIn);
	void printPlayerInfo();

	void setWinner();
	bool isWinner();
};