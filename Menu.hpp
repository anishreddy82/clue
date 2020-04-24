#pragma once
#include <vector>
#include "Player.hpp"
#include <cstdlib>
#include <ctime>

class Menu {
private:
	std::vector<Player> players;
	std::vector<char> colors;
public:
	Menu();
	std::vector<Player> setup(int x);
	char generate_color();
};