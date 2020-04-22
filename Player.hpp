#pragma once
#include <string>
class Player
{
private:
	int id;
	std::string name;
	char color;
	std::string password;
public:
	Player();
	Player(int idIn);
	std::string getName();
	int getId();
	char getColor();
	void setName(std::string nameIn);
	void setColor(char colorIn);
	void setPassword(std::string passwordIn);
	bool checkPassword(std::string stringIn);
};