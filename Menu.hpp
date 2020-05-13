#pragma once
#include <vector>
#include "Player.hpp"
#include <cstdlib>
#include <ctime>

class Menu {
private:
	std::vector<Player> players;
	std::vector<char> colors;
	std::vector<int> positions;
public:
	Menu();
	std::vector<Player> setup(int x);
	char generate_color();
	int generate_randPos();
	void setupPlayerName(Player &current_player);
	void setupPlayerColor(Player &current_player);
	void setupPlayerPassword(Player &current_player);
};