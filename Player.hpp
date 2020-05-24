#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
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
	int location;
	bool hasLost;

public:

	Player();
	Player(int idIn);
	std::vector<Card> hand;
	std::vector<sf::Sprite> notes;
	
	std::string getName();
	void showHand();
	void viewNotebook();
	void useNotebook(int);
	int getId();
	char getColor();
	int getPositionX();
	int getPositionY();
	int getLocation();
	bool getHasLost();
	void setHasLost();
	void setLocation(int loc);
	void setName(std::string nameIn);
	void setColor(char colorIn);
	void setStartingPosition(int pos);
	void setStartingPosition();
	void setPassword(std::string passwordIn);
	void setPositionX(int posX1);
	void setPositionY(int posY1);
	bool checkPassword(std::string stringIn);
	void printPlayerInfo();
	bool holdsCard(std::string cardName);
};
