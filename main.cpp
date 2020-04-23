#include <iostream>
#include "Player.hpp"
#include "Menu.hpp"

int main() {
	Menu main_menu = Menu();
	int player_count;
	//prompt to confirm game setup
	std::cout << "How many players for the game? (min 4, max 6)" << std::endl;
	std::cin >> player_count;
	std::cin.clear();
	std::cin.ignore(10000, '\n'); //skips the newline char on input

	//loop for invalid player count inputs
	while (player_count > 6 || player_count < 4) {
		//prompt to confirm game setup
		std::cout << "Please input a valid player count. (min 4, max 6)" << std::endl;

		std::cin >> player_count;

		std::cin.clear();
		std::cin.ignore(10000, '\n'); //skips the newline char on input
	}
	
	//begin game setup
	std::vector<Player> game_players = main_menu.setup(player_count);


	/*
	PRINT PLAYER INFO FOR TESTING
	*/
	std::cout << "_______________________________________________________________" << std::endl;
	for (int i = 0; i < player_count; i++) {
		if (game_players.at(i).checkPassword("123")) {
			game_players.at(i).printPlayerInfo();
		}
	}


	return 0;
}