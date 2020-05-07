#pragma once
#include <vector>
#include "Player.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <utility>
#include "room.hpp"
#include "Card.hpp"

class Board {
private:
	int w;
	int h;
	std::vector<std::pair<int, int>> player_coords;
public:
	Board();

	void dif(std::vector<Player>);
	Room** boardArray;
	std::vector<Card> murderCards;
};