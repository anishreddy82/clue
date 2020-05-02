#pragma once
#include <vector>
#include "Player.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include "room.hpp"
#include "Card.hpp"

class Board{
private:
	
public:
	void dif(std::vector<Player>);
     Room **boardArray;
	 std::vector<Card> murderCards;
};